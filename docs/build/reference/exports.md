---
title: EXPORTS
ms.date: 09/07/2018
f1_keywords:
- EXPORTS
helpviewer_keywords:
- EXPORTS .def file statement
ms.assetid: dbcd7579-b855-44c4-bd27-931e157657f7
ms.openlocfilehash: 9ede0d3b53c975298dea3d1331bc0fb00ac246b2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328251"
---
# <a name="exports"></a>EXPORTS

Introduz uma seção de uma ou mais definições de exportação que especificam os nomes exportados ou ordenais de funções ou dados. Cada definição deve ficar em uma linha separada.

```DEF
EXPORTS
   definition
```

## <a name="remarks"></a>Comentários

A primeira *definição* pode ser na `EXPORTS` mesma linha que a palavra-chave ou em uma linha subseqüente. O arquivo .DEF pode conter uma ou mais instruções `EXPORTS`.

A sintaxe para uma *definição* de exportação é:

> *nome*\[__=__*de*|entrada internal_name \[ **\@***other_module.exported_name*] _ordinal_ \[ **NONAME**] \[ \[ **] PRIVADO**] | \[ **DADOS**]

*nome de entrada* é a função ou nome de variável que você deseja exportar. Isso é necessário. Se o nome que você exportar difere do nome na DLL, especifique o nome da exportação na DLL usando *internal_name*. Por exemplo, se o DLL exportar uma função `func1` e você desejar que os chamadores a utilizem como `func2`, especifique:

```DEF
EXPORTS
   func2=func1
```

Se o nome que você exportar for de algum outro módulo, especifique o nome da exportação na DLL usando *other_module.exported_name*. Por exemplo, se o DLL exportar uma função `other_module.func1` e você desejar que os chamadores a utilizem como `func2`, especifique:

```DEF
EXPORTS
   func2=other_module.func1
```

Se o nome que você exportar for de outro módulo que exporte por ordinal, especifique a ordinal da exportação na DLL usando *other_module*. __#__ *ordinal*. Por exemplo, se o seu DLL exportar uma função do outro módulo onde ela é ordinal 42, e você quiser que os chamadores a usem como `func2`, você especificaria:

```DEF
EXPORTS
   func2=other_module.#42
```

Como o compilador MSVC usa decoração de nome para funções C++, você deve usar o `extern "C"` nome decorado *internal_name* ou definir as funções exportadas usando no código-fonte. O compilador também decora funções C que utilizam a [convenção de chamada __stdcall](../../cpp/stdcall.md) com um prefixo sublinhado (\_) e um sufixo composto do sinal at (\@) seguido pelo número de bytes (em decimal) na lista de argumentos.

Para encontrar os nomes decorados produzidos pelo compilador, use a ferramenta [DUMPBIN](dumpbin-reference.md) ou a opção linker [/MAP.](map-generate-mapfile.md) Os nomes decorados são específicos do compilador. Se você exportar os nomes decorados no arquivo .DEF, executáveis vinculados ao DLL também devem ser construídos com a mesma versão do compilador. Isso garante que os nomes decorados no chamador correspondam aos nomes exportados no arquivo .DEF.

Você pode \@usar *ordinal* para especificar que um número, e não o nome da função, entra na tabela de exportação da DLL. Muitos DLLs do Windows exportam ordinais para dar suporte a código legado. Era comum usar ordinais em código do Windows de 16 bits, pois isso podia ajudar a minimizar o tamanho de um DLL. Não recomendamos exportar funções por ordinal a menos que os clientes da sua DLL precisem dela para suporte legado. Como o arquivo .LIB conterá o mapeamento entre o ordinal e a função, é possível usar o nome da função como normalmente se faria em projetos que usam o DLL.

Usando a palavra-chave **noname** opcional, você pode exportar apenas por ordinal e reduzir o tamanho da tabela de exportação na DLL resultante. No entanto, se você quiser usar [GetProcAddress](/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) na DLL, você deve saber a ordinal porque o nome não será válido.

A palavra-chave opcional **PRIVATE** impede que o nome de *entrada* seja incluído na biblioteca de importação gerada pelo LINK. Não afeta a exportação na imagem também gerada por LINK.

A palavra-chave opcional **DATA** especifica que uma exportação é dados, não código. Esse exemplo mostra como exportar uma variável de dados chamada `exported_global`:

```DEF
EXPORTS
   exported_global DATA
```

Há quatro maneiras de exportar uma definição, listadas na ordem recomendada:

1. A [palavra-chave __declspec(dllexport)](../../cpp/dllexport-dllimport.md) no código-fonte

1. Uma instrução `EXPORTS` em um arquivo .DEF

1. Uma [especificação /EXPORT](export-exports-a-function.md) em um comando LINK

1. Uma diretiva [de comentário](../../preprocessor/comment-c-cpp.md) no código `#pragma comment(linker, "/export: definition ")`fonte, do formulário. O exemplo a seguir mostra uma diretiva `PlainFuncName` de comentário #pragma antes `_PlainFuncName@4` de uma declaração de função, onde está o nome não decorado, e é o nome condecorado da função:

    ```cpp
    #pragma comment(linker, "/export:PlainFuncName=_PlainFuncName@4")
    BOOL CALLBACK PlainFuncName( Things * lpParams)
    ```

A diretiva #pragma é útil se você precisar exportar um nome de função não decorado e ter exportações diferentes dependendo da configuração de compilação (por exemplo, em compilações de 32 bits ou 64 bits).

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

## <a name="see-also"></a>Confira também

[Regras para instruções de definição do módulo](rules-for-module-definition-statements.md)
