import requests
import json

class CurrencyConverter:
    def __init__(self):
        self.base_url = "https://api.exchangerate-api.com/v4/latest/"
        self.supported_currencies = ['USD', 'EUR', 'GBP', 'JPY', 'CNY', 'CAD', 'AUD', 'CHF', 'HKD', 'SGD']
    
    def get_exchange_rate(self, from_currency, to_currency):
        """获取汇率"""
        try:
            if from_currency == to_currency:
                return 1.0
            
            # 调用API获取汇率数据
            response = requests.get(f"{self.base_url}{from_currency}")
            response.raise_for_status()
            
            data = response.json()
            
            if to_currency in data['rates']:
                return data['rates'][to_currency]
            else:
                return None
                
        except requests.exceptions.RequestException as e:
            print(f"网络请求错误: {e}")
            return None
        except json.JSONDecodeError as e:
            print(f"数据解析错误: {e}")
            return None
    
    def convert_currency(self, amount, from_currency, to_currency):
        """转换货币"""
        # 验证输入
        try:
            amount = float(amount)
        except ValueError:
            return "错误：金额必须是数字"
        
        from_currency = from_currency.upper()
        to_currency = to_currency.upper()
        
        # 验证货币代码
        if from_currency not in self.supported_currencies:
            return f"错误：不支持的原货币代码 {from_currency}"
        if to_currency not in self.supported_currencies:
            return f"错误：不支持的目标货币代码 {to_currency}"
        
        # 获取汇率
        exchange_rate = self.get_exchange_rate(from_currency, to_currency)
        
        if exchange_rate is None:
            return "错误：无法获取汇率数据"
        
        # 计算转换结果
        converted_amount = amount * exchange_rate
        
        return {
            'original_amount': amount,
            'original_currency': from_currency,
            'converted_amount': round(converted_amount, 2),
            'target_currency': to_currency,
            'exchange_rate': round(exchange_rate, 4)
        }
    
    def show_supported_currencies(self):
        """显示支持的货币列表"""
        print("支持的货币代码:")
        currencies_info = {
            'USD': '美元',
            'EUR': '欧元', 
            'GBP': '英镑',
            'JPY': '日元',
            'CNY': '人民币',
            'CAD': '加元',
            'AUD': '澳元',
            'CHF': '瑞士法郎',
            'HKD': '港币',
            'SGD': '新加坡元'
        }
        
        for code, name in currencies_info.items():
            print(f"  {code} - {name}")

def main():
    converter = CurrencyConverter()
    
    print("=== 简易外汇转换器 ===")
    
    while True:
        print("\n" + "="*40)
        converter.show_supported_currencies()
        print("="*40)
        
        # 获取用户输入
        try:
            amount = input("\n请输入要兑换的金额 (输入 'q' 退出): ").strip()
            if amount.lower() == 'q':
                break
            
            from_currency = input("请输入原货币代码 (如: USD): ").strip().upper()
            to_currency = input("请输入目标货币代码 (如: CNY): ").strip().upper()
            
            # 执行转换
            result = converter.convert_currency(amount, from_currency, to_currency)
            
            # 显示结果
            if isinstance(result, dict):
                print(f"\n兑换结果:")
                print(f"{result['original_amount']} {result['original_currency']} = "
                      f"{result['converted_amount']} {result['target_currency']}")
                print(f"汇率: 1 {result['original_currency']} = {result['exchange_rate']} {result['target_currency']}")
            else:
                print(result)
                
        except KeyboardInterrupt:
            print("\n\n程序已退出")
            break
        except Exception as e:
            print(f"发生错误: {e}")

if __name__ == "__main__":
    main()
