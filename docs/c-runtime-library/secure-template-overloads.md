---
title: Sobrecargas de modelo seguras
description: Uma descrição das sobrecargas de modelo do Microsoft C Runtime que fornecem funções com segurança avançada.
ms.date: 11/04/2016
ms.topic: conceptual
f1_keywords:
- _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
- _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
- _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT
helpviewer_keywords:
- _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
- _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
- _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT
- secure template overloads
ms.assetid: 562741d0-39c0-485e-8529-73d740f29f8f
ms.openlocfilehash: 5e795d4d68aaeb176ba0809a08310def23662028
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91589634"
---
# <a name="secure-template-overloads"></a>Sobrecargas de modelo seguras

A Microsoft preteriu muitas funções CRT (biblioteca de runtime C) em favor de versões com segurança aprimorada. Por exemplo, `strcpy_s` é o substituto mais seguro de `strcpy`. As funções preteridas são fontes comuns de bugs de segurança, pois não impedem operações que possam substituir a memória. Por padrão, o compilador gerará um aviso de substituição quando você usar uma dessas funções. A CRT fornece sobrecargas de modelo do C++ para essas funções para ajudar a facilitar a transição para as variantes mais seguras.

Por exemplo, este snippet de código gera um aviso porque `strcpy` foi preterido:

```cpp
char szBuf[10];
strcpy(szBuf, "test"); // warning: deprecated
```

O aviso de substituição existe para informá-lo de que o código pode não ser seguro. Se você verificou que seu código não pode substituir a memória, você tem várias opções. Você pode optar por ignorar o aviso, pode definir o símbolo `_CRT_SECURE_NO_WARNINGS` antes das instruções include para cabeçalhos CRT para suprimir o aviso ou pode atualizar o código para usar `strcpy_s`:

```cpp
char szBuf[10];
strcpy_s(szBuf, 10, "test"); // security-enhanced _s function
```

As sobrecargas de modelo oferecem opções adicionais. Se você definir `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` como 1, isso habilitará as sobrecargas de modelo das funções de CRT padrão que chamam as variantes mais seguras automaticamente. Se `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` for 1, nenhuma alteração no código é necessária. Nos bastidores, a chamada para `strcpy` é alterada para uma chamada para `strcpy_s` com o argumento de tamanho fornecido automaticamente.

```cpp
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

// ...

char szBuf[10];
strcpy(szBuf, "test"); // ==> strcpy_s(szBuf, 10, "test")
```

A macro `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` não afeta as funções que usam uma contagem, como `strncpy` . Para habilitar as sobrecargas de modelo para funções de contagem, defina `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT` como 1. Antes de fazer isso, no entanto, certifique-se de que seu código passa a contagem de caracteres, não o tamanho do buffer (um erro comum). Além disso, um código que grave explicitamente um terminador nulo ao final do buffer após a chamada de função não é necessário se a variante segura for chamada. Se você precisar de comportamento de truncamento, consulte [_TRUNCATE](../c-runtime-library/truncate.md).

> [!NOTE]
> A macro `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT` requer que `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` também seja definida como 1. Se `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT` for definida como 1 e `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` for definida como 0, o aplicativo não executará sobrecargas de modelo.

Quando você define `_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES` como 1, ele permite sobrecargas de modelo das variantes seguras (nomes terminando em "_s"). Nesse caso, se `_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES` for 1, uma pequena alteração deverá ser feita no código original:

```cpp
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1

// ...

char szBuf[10];
strcpy_s(szBuf, "test"); // ==> strcpy_s(szBuf, 10, "test")
```

Somente o nome da função precisa ser alterado (adicionando “_s”); a sobrecarga de modelo se encarrega de fornecer o argumento de tamanho.

Por padrão, `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` e `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT` são definidas como 0 (desabilitada) e `_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES` é definida como 1 (ativada).

Essas sobrecargas de modelo funcionam apenas para matrizes estáticas. Buffers alocados dinamicamente exigem alterações de código de origem adicionais. Revisitando os exemplos anteriores:

```cpp
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

// ...

char *szBuf = (char*)malloc(10);
strcpy(szBuf, "test"); // still deprecated; change it to
                       // strcpy_s(szBuf, 10, "test");
```

E este:

```cpp
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1

// ...

char *szBuf = (char*)malloc(10);
strcpy_s(szBuf, "test"); // doesn't compile; change it to
                         // strcpy_s(szBuf, 10, "test");
```

## <a name="see-also"></a>Confira também

[Recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md)<br/>
[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
