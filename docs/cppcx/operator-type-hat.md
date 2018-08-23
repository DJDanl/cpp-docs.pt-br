---
title: operador Type ^ | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: b24ffc83-0780-4f9a-8ee0-f5725db339d1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9c0bca9d1f60820b7ceeba633eead0aa9e572be5
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42612904"
---
# <a name="operator-type"></a>operador Type^
Habilita a conversão de [Windows::UI::Xaml::Interop::TypeName](http://msdn.microsoft.com/library/windows/apps/windows.ui.xaml.interop.typename.aspx) para `Platform::Type`.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
Operator Type^(Windows::UI::Xaml::Interop::TypeName typeName)  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um `Platform::Type` quando um [Windows::UI::Xaml::Interop::TypeName](http://msdn.microsoft.com/library/windows/apps/windows.ui.xaml.interop.typename.aspx)é especificado.  
  
### <a name="remarks"></a>Comentários  
 `TypeName` é a estrutura do Tempo de Execução do Windows com neutralidade de idioma para representar informações de tipo. [Platform::Type](../cppcx/platform-type-class.md) é específico a C++ e não pode ser passado pela ABI (interface de binária de aplicativo). Aqui está um uso de `TypeName`na função [Navigate](http://msdn.microsoft.com/library/windows/apps/hh702394.aspx) :  
  
```  
rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);  
```  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como converter entre `TypeName` e `Type`.  
  
```  
  
// Convert from Type to TypeName  
TypeName tn = TypeName(MainPage::typeid);  
  
// Convert back from TypeName to Type  
Type^ tx2 = (Type^)(tn);  
  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 O .NET Framework programa o `TypeName` do projeto como [System.Type](assetId:///System.Type?qualifyHint=False&autoUpgrade=True).  
  
### <a name="requirements"></a>Requisitos  
  
## <a name="see-also"></a>Consulte também  
 [operador Windows::UI::Xaml::Interop::TypeName](../cppcx/operator-windows-ui-xaml-interop-typename.md)   
 [Classe Platform::Type](../cppcx/platform-type-class.md)