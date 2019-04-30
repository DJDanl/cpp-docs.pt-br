---
title: Aviso LNK4049 (Ferramentas de Vinculador)
ms.date: 04/15/2019
f1_keywords:
- LNK4049
helpviewer_keywords:
- LNK4049
ms.assetid: 5fd5fb24-c860-4149-a557-0ac26a65d97c
ms.openlocfilehash: b527d15310dba70c1bae21e601db17db2900e219
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410233"
---
# <a name="linker-tools-warning-lnk4049"></a>Aviso LNK4049 (Ferramentas de Vinculador)

> símbolo de '*símbolo*'definido em'*filename. obj*' é importado

[__declspec(DllImport)](../../cpp/dllexport-dllimport.md) foi especificado para *símbolo* mesmo que o símbolo é definido no arquivo de objeto *filename. obj* na mesma imagem. Remover o `__declspec(dllimport)` modificador para resolver este aviso.

## <a name="remarks"></a>Comentários

Esse aviso é gerado pelo vinculador quando você define um símbolo no arquivo de um objeto e referenciá-lo usando o `__declspec(dllimport)` modificador de declaração em outro.

Aviso LNK4049 é uma versão mais geral do [LNK4217 de aviso de ferramentas de vinculador](linker-tools-warning-lnk4217.md). O vinculador gera o aviso LNK4049 quando não é possível determinar qual arquivo de função ou o objeto referenciado no símbolo importado.

Casos comuns onde LNK4049 é gerado em vez de LNK4217 são:

- Ao usar o [/incremental](../../build/reference/incremental-link-incrementally.md) opção.

- Ao usar o [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) opção.

Para resolver LNK4049, tente um dos procedimentos a seguir:

- Remover o `__declspec(dllimport)` modificador de declaração de encaminhamento do símbolo que disparou LNK4049. Você pode pesquisar símbolos em uma imagem binária usando o **DUMPBIN** utilitário. O **/SYMBOLS (DUMPBIN)** opção exibe a tabela de símbolos COFF da imagem. Para obter mais informações sobre o **DUMPBIN** utilitário, consulte [referência de DUMPBIN](../../build/reference/dumpbin-reference.md).

- Desabilite temporariamente a vinculação incremental e a otimização de programa inteiro. Quando recompilado, o aplicativo gera o aviso LNK4217, que inclui o nome da função que faz referência o símbolo importado. Remover o `__declspec(dllimport)` modificador de declaração do símbolo importado e habilite novamente a vinculação incremental ou otimização de programa inteiro conforme necessário.

Embora o código gerado final se comporta corretamente, o código gerado para chamar a função importada é menos eficiente do que chamar a função diretamente. Esse aviso não aparece quando você compila usando o [/clr](../../build/reference/clr-common-language-runtime-compilation.md) opção.

Para obter mais informações sobre importar e exportar dados de declarações, consulte [dllexport, dllimport](../../cpp/dllexport-dllimport.md).

## <a name="example"></a>Exemplo

Vincular os dois seguintes módulos irá gerar LNK4049. O primeiro módulo gera um arquivo de objeto que contém uma única função exportada.

```cpp
// LNK4049a.cpp
// compile with: /c

__declspec(dllexport) int func()
{
   return 3;
}
```

O segundo módulo gera um arquivo de objeto que contém uma declaração de encaminhamento para a função exportada no primeiro módulo, juntamente com uma chamada para essa função dentro de `main` função. Vincular este módulo com o primeiro módulo irá gerar LNK4049. Remover o `__declspec(dllimport)` modificador da declaração para resolver o aviso.

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

## <a name="see-also"></a>Consulte também

[Aviso LNK4217 ferramentas de vinculador](linker-tools-warning-lnk4217.md) \
[Aviso LNK4286 ferramentas de vinculador](linker-tools-warning-lnk4286.md) \
[dllexport, dllimport](../../cpp/dllexport-dllimport.md)