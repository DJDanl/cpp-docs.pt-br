---
title: Aviso LNK4049 (Ferramentas de Vinculador)
ms.date: 04/15/2019
f1_keywords:
- LNK4049
helpviewer_keywords:
- LNK4049
ms.assetid: 5fd5fb24-c860-4149-a557-0ac26a65d97c
ms.openlocfilehash: a8e4416eafd47f584de4ab1c83aa7303cab0440a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194129"
---
# <a name="linker-tools-warning-lnk4049"></a>Aviso LNK4049 (Ferramentas de Vinculador)

> o símbolo '*Symbol*' definido em '*filename. obj*' é importado

[__declspec (dllimport)](../../cpp/dllexport-dllimport.md) foi especificado para *símbolo* , embora o símbolo esteja definido no arquivo de objeto *filename. obj* na mesma imagem. Remova o modificador de `__declspec(dllimport)` para resolver este aviso.

## <a name="remarks"></a>Comentários

Esse aviso é gerado pelo vinculador quando você define um símbolo em um arquivo de objeto e faz referência a ele usando o modificador de declaração de `__declspec(dllimport)` em outro.

Aviso LNK4049 é uma versão mais geral do [aviso de ferramentas do vinculador LNK4217](linker-tools-warning-lnk4217.md). O vinculador gera um aviso LNK4049 quando não é possível determinar qual arquivo de função ou objeto referenciou o símbolo importado.

Os casos comuns em que LNK4049 é gerado em vez de LNK4217 são:

- Ao usar a opção [/incremental](../../build/reference/incremental-link-incrementally.md) .

- Ao usar a opção [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) .

Para resolver o LNK4049, tente um dos seguintes procedimentos:

- Remova o modificador `__declspec(dllimport)` da declaração de encaminhamento do símbolo que disparou LNK4049. Você pode procurar símbolos em uma imagem binária usando o utilitário **DUMPBIN** . A opção **DUMPBIN/Symbols** exibe a tabela de símbolos COFF da imagem. Para obter mais informações sobre o utilitário **DUMPBIN** , consulte [referência do DUMPBIN](../../build/reference/dumpbin-reference.md).

- Desabilite temporariamente a vinculação incremental e a otimização de todo o programa. Quando recompilado, o aplicativo gera o aviso LNK4217, que inclui o nome da função que faz referência ao símbolo importado. Remova o modificador de declaração `__declspec(dllimport)` do símbolo importado e reabilite a vinculação incremental ou a otimização do programa inteiro, conforme necessário.

Embora o código gerado final se comporta corretamente, o código gerado para chamar a função importada é menos eficiente do que chamar a função diretamente. Esse aviso não aparece quando você compila usando a opção [/CLR](../../build/reference/clr-common-language-runtime-compilation.md) .

Para obter mais informações sobre como importar e exportar declarações de dados, consulte [dllexport, DllImport](../../cpp/dllexport-dllimport.md).

## <a name="example"></a>Exemplo

Vincular os dois módulos a seguir irá gerar LNK4049. O primeiro módulo gera um arquivo de objeto que contém uma única função exportada.

```cpp
// LNK4049a.cpp
// compile with: /c

__declspec(dllexport) int func()
{
   return 3;
}
```

O segundo módulo gera um arquivo de objeto que contém uma declaração de encaminhamento para a função exportada no primeiro módulo, juntamente com uma chamada para essa função dentro da função `main`. Vincular este módulo ao primeiro módulo gerará LNK4049. Remova o modificador `__declspec(dllimport)` da declaração para resolver o aviso.

```cpp
// LNK4049b.cpp
// compile with: /link /WX /LTCG LNK4049a.obj
// LNK4049 expected

__declspec(dllimport) int func();
// try the following line instead
// int func();

int main()
{
   return func();
}
```

## <a name="see-also"></a>Confira também

[LNK4217 de aviso das ferramentas do vinculador](linker-tools-warning-lnk4217.md) \
[LNK4286 de aviso das ferramentas do vinculador](linker-tools-warning-lnk4286.md) \
[dllexport, dllimport](../../cpp/dllexport-dllimport.md)
