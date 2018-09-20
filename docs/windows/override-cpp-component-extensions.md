---
title: Substituir (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- overriding, override keyword [C++]
- override keyword [C++]
ms.assetid: 34d19257-1686-4fcd-96f5-af07c70ba914
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6071cef3d5669fda86975bb0f27a2b9b87eeb011
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46407264"
---
# <a name="override--c-component-extensions"></a>substituir (Extensões de Componentes C++)

O **substituir** palavra-chave contextual indica que um membro de um tipo substitui uma classe base ou um membro de interface base.

## <a name="remarks"></a>Comentários

O **substituir** palavra-chave é válido ao compilar para destinos nativos (opção do compilador padrão), as metas de tempo de execução do Windows (`/ZW` opção de compilador), ou destinos de tempo de execução de linguagem comum (`/clr` opção de compilador).

Para obter mais informações sobre especificadores de substituição, consulte [especificador de substituição](../cpp/override-specifier.md) e [especificadores de substituição e compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).

Para obter mais informações sobre palavras-chave contextuais, consulte [contextual as palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md).

## <a name="examples"></a>Exemplos

O exemplo de código a seguir mostra que **substituir** também podem ser usados em compilações nativas.

```cpp
// override_keyword_1.cpp
// compile with: /c
struct I1 {
   virtual void f();
};

struct X : public I1 {
   virtual void f() override {}
};
```

### <a name="example"></a>Exemplo

O exemplo de código a seguir mostra que **substituir** pode ser usado em compilações de tempo de execução do Windows.

```cpp 
// override_keyword_2.cpp
// compile with: /ZW /c
ref struct I1 {
   virtual void f();
};

ref struct X : public I1 {
   virtual void f() override {}
};
```

#### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

### <a name="example"></a>Exemplo

O exemplo de código a seguir mostra que **substituir** pode ser usado em compilações de tempo de execução de linguagem comum.

```cpp
// override_keyword_3.cpp
// compile with: /clr /c
ref struct I1 {
   virtual void f();
};

ref struct X : public I1 {
   virtual void f() override {}
};
```

#### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

## <a name="see-also"></a>Consulte também

[Especificador override](../cpp/override-specifier.md)<br/>
[Especificadores de substituição](../windows/override-specifiers-cpp-component-extensions.md)