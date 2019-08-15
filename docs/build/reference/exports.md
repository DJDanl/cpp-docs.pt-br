---
title: EXPORTS
ms.date: 09/07/2018
f1_keywords:
- EXPORTS
helpviewer_keywords:
- EXPORTS .def file statement
ms.assetid: dbcd7579-b855-44c4-bd27-931e157657f7
ms.openlocfilehash: 8338f27d35d3779a55b83b70c7a3eef285a91f46
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492891"
---
# <a name="exports"></a>EXPORTS

Introduz uma seção de uma ou mais definições de exportação que especificam os nomes exportados ou ordenais de funções ou dados. Cada definição deve ficar em uma linha separada.

```DEF
EXPORTS
   definition
```

## <a name="remarks"></a>Comentários

A primeira *definição* pode estar na mesma linha que a `EXPORTS` palavra-chave ou em uma linha subsequente. O arquivo .DEF pode conter uma ou mais instruções `EXPORTS`.

A sintaxe para uma *definição* de exportação é:

> *entryname*\[ __=__ *internal_name*|*other_module.exported_name*] \[ **\@** _ordinal_ \[**NONAME**] ] \[ \[**PRIVATE**] | \[**DATA**] ]

*entryname* é o nome da função ou da variável que você deseja exportar. É obrigatório. Se o nome que você exportar diferir do nome na DLL, especifique o nome da exportação na DLL usando *internal_name*. Por exemplo, se o DLL exportar uma função `func1` e você desejar que os chamadores a utilizem como `func2`, especifique:

```DEF
EXPORTS
   func2=func1
```

Se o nome que você exportar for de algum outro módulo, especifique o nome da exportação na DLL usando *other_module. exported_name*. Por exemplo, se o DLL exportar uma função `other_module.func1` e você desejar que os chamadores a utilizem como `func2`, especifique:

```DEF
EXPORTS
   func2=other_module.func1
```

Se o nome que você exportar for de outro módulo que exporta por ordinal, especifique o ordinal da exportação na DLL usando *other_module*. __#__ *ordinal*. Por exemplo, se sua dll exporta uma função do outro módulo onde ela é ordinal 42 e você deseja que os chamadores as usem como `func2`, você deve especificar:

```DEF
EXPORTS
   func2=other_module.#42
```

Como o compilador MSVC usa decoração de nome C++ para funções, você deve usar o nome decorado *internal_name* ou definir as funções exportadas usando `extern "C"` no código-fonte. O compilador também decora as funções de C que usam a Convenção de chamada [__stdcall](../../cpp/stdcall.md) com um prefixo\_de sublinhado () e um sufixo composto pelo\@sinal de arroba () seguido pelo número de bytes (em decimal) na lista de argumentos.

Para localizar os nomes decorados produzidos pelo compilador, use a ferramenta [DUMPBIN](dumpbin-reference.md) ou a opção [/MAP](map-generate-mapfile.md) do vinculador. Os nomes decorados são específicos do compilador. Se você exportar os nomes decorados no arquivo .DEF, executáveis vinculados ao DLL também devem ser construídos com a mesma versão do compilador. Isso garante que os nomes decorados no chamador correspondam aos nomes exportados no arquivo .DEF.

Você pode usar \@ *ordinal* para especificar que um número, e não o nome da função, vá para a tabela de exportação da dll. Muitos DLLs do Windows exportam ordinais para dar suporte a código legado. Era comum usar ordinais em código do Windows de 16 bits, pois isso podia ajudar a minimizar o tamanho de um DLL. Não recomendamos exportar funções por ordinais, a menos que os clientes DLL precisem disso para suporte legado. Como o arquivo .LIB conterá o mapeamento entre o ordinal e a função, é possível usar o nome da função como normalmente se faria em projetos que usam o DLL.

Usando a palavra-chave opcional **NoName** , você pode exportar somente por ordinal e reduzir o tamanho da tabela de exportação na DLL resultante. No entanto, se você quiser usar [GetProcAddress](/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) na DLL, deverá saber o ordinal porque o nome não será válido.

A palavra-chave opcional **Private** impede que o *entryname* seja incluído na biblioteca de importação gerada pelo link. Não afeta a exportação na imagem também gerada por LINK.

Os **dados** de palavra-chave opcional especificam que uma exportação é de dados, não de código. Esse exemplo mostra como exportar uma variável de dados chamada `exported_global`:

```DEF
EXPORTS
   exported_global DATA
```

Há quatro maneiras de exportar uma definição, listadas na ordem recomendada:

1. A palavra [ir_ declspec (dllexport)](../../cpp/dllexport-dllimport.md) no código-fonte

1. Uma instrução `EXPORTS` em um arquivo .DEF

1. Uma especificação [/Export](export-exports-a-function.md) em um comando link

1. Uma diretiva de [Comentário](../../preprocessor/comment-c-cpp.md) no código-fonte, do formulário `#pragma comment(linker, "/export: definition ")`. O exemplo a seguir mostra uma diretiva de comentário #pragma antes de uma declaração `PlainFuncName` de função, em que é o `_PlainFuncName@4` nome não decorado e é o nome decorado da função:

    ```cpp
    #pragma comment(linker, "/export:PlainFuncName=_PlainFuncName@4")
    BOOL CALLBACK PlainFuncName( Things * lpParams)
    ```

A diretiva #pragma será útil se você precisar exportar um nome de função não decorado e tiver exportações diferentes dependendo da configuração da compilação (por exemplo, em builds de 32 bits ou 64 bits).

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
