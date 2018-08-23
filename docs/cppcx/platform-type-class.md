---
title: 'Classe Platform:: Type | Microsoft Docs'
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Type::GetTypeCode
- VCCORLIB/Platform::Type::FullName
dev_langs:
- C++
helpviewer_keywords:
- Platform::Type Class
ms.assetid: d6b03f1e-b240-49b9-a08e-53a460030475
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e4d2931df50c6bfac126bc8e8ab1c70d61bdfe39
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42596695"
---
# <a name="platformtype-class"></a>Classe Platform::Type
Contém informações de tempo de execução sobre um tipo, especificamente um nome de cadeia de caracteres e um typecode. Obtido chamando [Object:: GetType](../cppcx/platform-object-class.md#gettype) em qualquer objeto ou usando o [typeid](../windows/typeid-cpp-component-extensions.md) operador em um nome de classe ou struct.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
public ref class Platform::Type :      
    Platform::Object, Platform::Details::IEquatable,
    Platform::Details::IPrintable  
```  
  
### <a name="remarks"></a>Comentários  
 A classe `Type` é útil em aplicativos que devem direcionar o processamento usando uma instrução `if` ou `switch` que se ramifica de acordo com o tipo de tempo de execução de um objeto. O código de tipo que descreve a categoria de um tipo é recuperado usando o [Type:: GetTypeCode](#gettypecode) função de membro.  
  
## <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|[Método Type::GetTypeCode](#gettypecode)|Retorna um valor de [Enumeração Platform::TypeCode](../cppcx/platform-typecode-enumeration.md) para o objeto.| 
|[Método Type::ToString](#tostring)|Retorna o nome do tipo especificado em seus metadados.| 

 
## <a name="public-properties"></a>Propriedades públicas  
  
|||  
|-|-|  
|[Type::FullName](#fullname)|Retorna uma [Classe Platform::String](../cppcx/platform-string-class.md)^ que representa o nome totalmente qualificado do tipo e usa . (ponto) como um separador, não:: (dois-pontos duplos) — por exemplo, `MyNamespace.MyClass`.|  
  
## <a name="conversion-operators"></a>Operadores de conversão  
  
|||  
|-|-|  
|[operador Type^](../cppcx/operator-type-hat.md)|Permite a conversão de `Windows::UI::Xaml::Interop::TypeName` em `Platform::Type`.|  
|[operador Windows::UI::Xaml::Interop::TypeName](../cppcx/operator-windows-ui-xaml-interop-typename.md)|Permite a conversão de `Platform::Type` em `Windows::UI::Xaml::Interop::TypeName`.|  
  
### <a name="requirements"></a>Requisitos  
 **Mínimo de cliente com suporte:** Windows 8  
  
 **Mínimo de servidor com suporte:** Windows Server 2012  
  
 **Namespace:** Platform  
  
 **Metadados:** platform.winmd  

 
## <a name="fullname"></a> Propriedade Type::FullName
Recupera o nome totalmente qualificado do tipo atual no formulário `Namespace.Type`.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
String^ FullName();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome do tipo.  
### <a name="example"></a>Exemplo  
  
```  
  
//  namespace is TestApp  
MainPage::MainPage()  
{  
    InitializeComponent();  
    Type^ t = this->GetType();  
    auto s = t->FullName; // returns "TestApp.MainPage"  
    auto s2 = t->ToString(); //also returns "TestApp.MainPage"  
}  
```  
  


## <a name="gettypecode"></a> Método Type::GetTypeCode
Recupera uma categoria de tipo numérico de tipos internos.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
Platform::TypeCode GetTypeCode();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores enumerados de Platform::TypeCode.  
  
### <a name="remarks"></a>Comentários  
 O equivalente do método membro GetTypeCode () é o `typeid` propriedade.

## <a name="tostring"></a> Método Type::ToString
Recupera um o nome do tipo.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
Platform::String^ ToString();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um nome do tipo especificado em seus metadados.    
  
## <a name="see-also"></a>Consulte também  
 [Namespace Platform](../cppcx/platform-namespace-c-cx.md)