---
title: operador Type^
ms.date: 12/30/2016
ms.assetid: b24ffc83-0780-4f9a-8ee0-f5725db339d1
ms.openlocfilehash: fca53abb9dc17588695591d496b7db2a76e319f6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50553654"
---
# <a name="operator-type"></a>operador Type^

Habilita a conversão de [Windows::UI::Xaml::Interop::TypeName](https://msdn.microsoft.com/library/windows/apps/windows.ui.xaml.interop.typename.aspx) para `Platform::Type`.

## <a name="syntax"></a>Sintaxe

```cpp
Operator Type^(Windows::UI::Xaml::Interop::TypeName typeName);
```

### <a name="return-value"></a>Valor de retorno

Retorna um `Platform::Type` quando um [Windows::UI::Xaml::Interop::TypeName](https://msdn.microsoft.com/library/windows/apps/windows.ui.xaml.interop.typename.aspx)é especificado.

### <a name="remarks"></a>Comentários

`TypeName` é a estrutura do Tempo de Execução do Windows com neutralidade de idioma para representar informações de tipo. [Platform::Type](../cppcx/platform-type-class.md) é específico a C++ e não pode ser passado pela ABI (interface de binária de aplicativo). Aqui está um uso de `TypeName`na função [Navigate](https://msdn.microsoft.com/library/windows/apps/hh702394.aspx) :

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

Projeto de programas do .NET framework `TypeName` como <xref:System.Type>

### <a name="requirements"></a>Requisitos

## <a name="see-also"></a>Consulte também

[operador Windows::UI::Xaml::Interop::TypeName](../cppcx/operator-windows-ui-xaml-interop-typename.md)<br/>
[Classe Platform::Type](../cppcx/platform-type-class.md)