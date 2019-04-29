---
title: EXPORTS
ms.date: 09/07/2018
f1_keywords:
- EXPORTS
helpviewer_keywords:
- EXPORTS .def file statement
ms.assetid: dbcd7579-b855-44c4-bd27-931e157657f7
ms.openlocfilehash: 33b70c680bfc3db24f5326a2027fa9ec4740e3f2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62271340"
---
# <a name="exports"></a>EXPORTS

Introduz uma seção de uma ou mais definições de exportação que especificam os nomes exportados ou ordenais de funções ou dados. Cada definição deve ficar em uma linha separada.

```DEF
EXPORTS
   definition
```

## <a name="remarks"></a>Comentários

A primeira *definition* pode ser na mesma linha como o `EXPORTS` palavra-chave ou em uma linha subsequente. O arquivo .DEF pode conter uma ou mais instruções `EXPORTS`.

A sintaxe para uma exportação *definição* é:

> *entryname*\[__=__*internal_name*|*other_module.exported_name*] \[**\@**_ordinal_ \[**NONAME**] ] \[ \[**PRIVATE**] | \[**DATA**] ]

*Nome_da_entrada* é o nome de função ou variável que você deseja exportar. É obrigatório. Se o nome exportado for diferente do nome na DLL, especifique o nome da exportação no DLL usando *internal_name*. Por exemplo, se o DLL exportar uma função `func1` e você desejar que os chamadores a utilizem como `func2`, especifique:

```DEF
EXPORTS
   func2=func1
```

Se o nome exportado for de algum outro módulo, especifica o nome da exportação no DLL usando *other_module.exported_name*. Por exemplo, se o DLL exportar uma função `other_module.func1` e você desejar que os chamadores a utilizem como `func2`, especifique:

```DEF
EXPORTS
   func2=other_module.func1
```

Se o nome exportado for de outro módulo que exporta por ordinal, especifique a exportação 's ordinal na DLL usando *other_module*.__#__ *ordinal*. Por exemplo, se sua DLL exporta uma função de outro módulo em que é ordinal 42, e você deseja que os chamadores para usá-la como `func2`, você especificaria:

```DEF
EXPORTS
   func2=other_module.#42
```

Como o compilador MSVC usa a decoração de nome para C++ funções, você deve usar o nome decorado *internal_name* ou definir as funções exportadas usando `extern "C"` no código-fonte. O compilador também decora funções C que usam o [stdcall](../../cpp/stdcall.md) chamando convenção com um sublinhado (\_) prefixo e um sufixo composto o sinal de arroba (\@) seguido pelo número de bytes (em decimais) no lista de argumentos.

Para localizar os nomes decorados produzidos pelo compilador, use o [DUMPBIN](dumpbin-reference.md) ferramenta ou o vinculador [/Map](map-generate-mapfile.md) opção. Os nomes decorados são específicos do compilador. Se você exportar os nomes decorados no arquivo .DEF, executáveis vinculados ao DLL também devem ser construídos com a mesma versão do compilador. Isso garante que os nomes decorados no chamador correspondam aos nomes exportados no arquivo .DEF.

Você pode usar \@ *ordinal* para especificar que um número e não o nome da função, entra em tabela de exportação da DLL. Muitos DLLs do Windows exportam ordinais para dar suporte a código legado. Era comum usar ordinais em código do Windows de 16 bits, pois isso podia ajudar a minimizar o tamanho de um DLL. Não recomendamos exportar funções por ordinais, a menos que os clientes DLL precisem disso para suporte legado. Como o arquivo .LIB conterá o mapeamento entre o ordinal e a função, é possível usar o nome da função como normalmente se faria em projetos que usam o DLL.

Com o uso opcional **NONAME** palavra-chave, você pode exportar apenas por ordinal e reduzir o tamanho da tabela de exportação no DLL resultante. No entanto, se você quiser usar [GetProcAddress](/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) no DLL, você deve conhecer o ordinal porque o nome não será válido.

A palavra-chave opcional **PRIVADOS** impede *Nome_da_entrada* sejam incluídos na biblioteca de importação gerada por LINK. Não afeta a exportação na imagem também gerada por LINK.

A palavra-chave opcional **dados** Especifica que uma exportação de dados, não código. Esse exemplo mostra como exportar uma variável de dados chamada `exported_global`:

```DEF
EXPORTS
   exported_global DATA
```

Há quatro maneiras de exportar uma definição, listadas na ordem recomendada:

1. O [dllexport](../../cpp/dllexport-dllimport.md) palavra-chave no código-fonte

1. Uma instrução `EXPORTS` em um arquivo .DEF

1. Uma [/exportação](export-exports-a-function.md) especificação em um comando LINK

1. Um [comentário](../../preprocessor/comment-c-cpp.md) diretiva no código-fonte do formulário `#pragma comment(linker, "/export: definition ")`. O exemplo a seguir mostra uma diretiva de comentário #pragma antes de uma declaração de função, onde `PlainFuncName` é o nome não decorado, e `_PlainFuncName@4` é o nome decorado da função:

    ```cpp
    #pragma comment(linker, "/export:PlainFuncName=_PlainFuncName@4")
    BOOL CALLBACK PlainFuncName( Things * lpParams)
    ```

A diretiva #pragma é útil se você precisar exportar um nome não decorado de função e ter exportações diferentes dependendo da configuração de build (por exemplo, em compilações de 32 bits ou 64 bits).

Todos os quatro métodos podem ser usados no mesmo programa. Quando LINK compila um programa que contém exportações, ele também cria uma biblioteca de importação, a menos que um arquivo .EXP seja usado na construção.

Segue um exemplo de seção EXPORTS:

```DEF
EXPORTS
   DllCanUnloadNow      @1          PRIVATE
   DllWindowName = WindowName       DATA
   DllGetClassObject    @4 NONAME   PRIVATE
   DllRegisterServer    @7
   DllUnregisterServer
```

Ao exportar uma variável de um DLL usando um arquivo .DEF, não é necessário especificar `__declspec(dllexport)` na variável. Porém, em qualquer arquivo que use o DLL, ainda é preciso usar `__declspec(dllimport)` na declaração de dados.

## <a name="see-also"></a>Consulte também

[Regras para instruções de definição do módulo](rules-for-module-definition-statements.md)
