---
title: Aviso LNK4217 (Ferramentas de Vinculador)
ms.date: 07/23/2019
f1_keywords:
- LNK4217
helpviewer_keywords:
- LNK4217
ms.assetid: 280dc03e-5933-4e8d-bb8c-891fbe788738
ms.openlocfilehash: 1301dd53f71c616d7b7af346923a54c42903c9fd
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68450855"
---
# <a name="linker-tools-warning-lnk4217"></a>Aviso LNK4217 (Ferramentas de Vinculador)

> o símbolo '*Symbol*' definido em '*filename_1. obj*' é importado por '*filename_2. obj*' na função '*Function*'

a [_ declspec (dllimport)](../../cpp/dllexport-dllimport.md) foi especificada para um símbolo, embora o símbolo seja definido em um arquivo de objeto na mesma imagem. Remova o `__declspec(dllimport)` modificador para resolver este aviso.

## <a name="remarks"></a>Comentários

*Symbol* é o nome do símbolo que é definido na imagem. *Function* é a função que está importando o símbolo.

Esse aviso não aparece quando você compila usando a opção [/CLR](../../build/reference/clr-common-language-runtime-compilation.md) .

O LNK4217 também pode ocorrer se você tentar vincular dois módulos juntos, quando, em vez disso, você deve compilar o segundo módulo com a biblioteca de importação do primeiro módulo.

```cpp
// main.cpp
__declspec(dllimport) void func();

int main()
{
    func();
    return 0;
}

```

E, em seguida,

```cpp
// tt.cpp
// compile with: /c
void func() {}
```

A tentativa de compilar esses dois módulos, conforme mostrado aqui, resultará em LNK4217:

```cmd
cl.exe /c main.cpp tt.cpp
link.exe main.obj tt.obj
```

Para corrigir o erro, depois de compilar os dois arquivos, passe TT. obj para lib. exe para criar um arquivo. lib e, em seguida, vincule Main. obj com TT. lib, conforme mostrado aqui:

```cmd
cl.exe /c main.cpp tt.cpp
lib.exe tt.obj /export:func /def
link.exe main.obj tt.lib
```

## <a name="see-also"></a>Consulte também

[LNK4049 de aviso das ferramentas do vinculador](linker-tools-warning-lnk4049.md) \
[LNK4286 de aviso das ferramentas do vinculador](linker-tools-warning-lnk4286.md) \
[dllexport, dllimport](../../cpp/dllexport-dllimport.md)