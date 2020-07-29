---
title: /Zc:strictStrings (Desativar conversão de tipo literal de cadeia de caracteres)
ms.date: 03/06/2018
f1_keywords:
- /Zc:strictStrings
- strictStrings
helpviewer_keywords:
- /Zc:strictStrings
- -Zc compiler options (C++)
- strictStrings
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: b7eb3f3b-82c1-48a2-8e63-66bad7397b46
ms.openlocfilehash: df880ed64fa472ff55eb5ee0d17caacf56228ab6
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211886"
---
# <a name="zcstrictstrings-disable-string-literal-type-conversion"></a>`/Zc:strictStrings`(Desabilitar conversão de tipo literal de cadeia de caracteres)

Quando especificado, o compilador requer **`const`** conformidade de qualificação estrita para ponteiros inicializados usando literais de cadeia de caracteres.

## <a name="syntax"></a>Sintaxe

> **`/Zc:strictStrings`**[**`-`**]

## <a name="remarks"></a>Comentários

Se **`/Zc:strictStrings`** for especificado, o compilador aplicará as **`const`** qualificações C++ padrão para literais de cadeia de caracteres, como o tipo ' array of `const char` ' ou ' array of `const wchar_t` ', dependendo da declaração. Os literais da cadeia de caracteres são imutáveis, e uma tentativa de modificar o conteúdo de um resulta em um erro de violação de acesso em tempo de execução. Você deve declarar um ponteiro de cadeia de caracteres como **`const`** inicializá-lo usando um literal de cadeia de caracteres ou usar um explícito **`const_cast`** para inicializar um não **`const`** ponteiro. Por padrão, ou se **`/Zc:strictStrings-`** for especificado, o compilador não imporá as **`const`** qualificações C++ padrão para ponteiros de cadeia de caracteres inicializados usando literais de cadeia de caracteres.

A **`/Zc:strictStrings`** opção está desativada por padrão. A [`/permissive-`](permissive-standards-conformance.md) opção do compilador define implicitamente essa opção, mas pode ser substituída usando **`/Zc:strictStrings-`** .

Use a **`/Zc:strictStrings`** opção para impedir a compilação de código incorreto. Este exemplo mostra como um erro de declaração simples leva a uma falha em tempo de execução:

```cpp
// strictStrings_off.cpp
// compile by using: cl /W4 strictStrings_off.cpp
int main() {
   wchar_t* str = L"hello";
   str[2] = L'a'; // run-time error: access violation
}
```

Quando **`/Zc:strictStrings`** é habilitado, o mesmo código relata um erro na declaração de `str` .

```cpp
// strictStrings_on.cpp
// compile by using: cl /Zc:strictStrings /W4 strictStrings_on.cpp
int main() {
   wchar_t* str = L"hello"; // error: Conversion from string literal
   // loses const qualifier
   str[2] = L'a';
}
```

Se você usar **`auto`** para declarar um ponteiro de cadeia de caracteres, o compilador criará a **`const`** declaração correta de tipo de ponteiro para você. Uma tentativa de modificar o conteúdo de um **`const`** ponteiro é relatada pelo compilador como um erro.

> [!NOTE]
> A biblioteca padrão C++ no Visual Studio 2013 não oferece suporte à **`/Zc:strictStrings`** opção de compilador em compilações de depuração. Se você vir vários erros de [C2665](../../error-messages/compiler-errors-2/compiler-error-c2665.md) em sua saída de compilação, isso pode ser a causa.

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções adicionais** para incluir **`/Zc:strictStrings`** e, em seguida, escolha **OK**.

## <a name="see-also"></a>Confira também

[`/Zc`Conformidade](zc-conformance.md)<br/>
