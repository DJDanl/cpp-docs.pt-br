---
title: Chamando funções DLL a partir de aplicativos Visual Basic
ms.date: 11/04/2016
helpviewer_keywords:
- functions [C++], calling DLL functions from Visual Basic
- DLL functions [C++]
- function calls [C++], DLL functions
- DLLs [C++], calling
- calling DLL functions from VB applications [C++]
- __stdcall keyword [C++]
- DLL functions [C++], calling
ms.assetid: 282f7fbf-a0f2-4b9f-b277-1982710be56c
ms.openlocfilehash: 23b5692e28b9ea5b70c492e2564b8bf5385b1815
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221201"
---
# <a name="calling-dll-functions-from-visual-basic-applications"></a>Chamando funções DLL a partir de aplicativos Visual Basic

Para aplicativos Visual Basic (ou aplicativos em outras linguagens, como Pascal ou Fortran) para chamar funções em uma DLL C/C++, as funções devem ser exportadas usando a Convenção de chamada correta sem qualquer decoração de nome feita pelo compilador

`__stdcall`cria a Convenção de chamada correta para a função (a função chamada limpa a pilha e os parâmetros são passados da direita para a esquerda), mas decora o nome da função de forma diferente. Assim, quando **__declspec (dllexport)** é usado em uma função exportada em uma dll, o nome decorado é exportado.

A `__stdcall` decoração de nome prefixa o nome do símbolo com um sublinhado ( **\_** ) e anexa o símbolo com um caractere**\@** de arroba () seguido pelo número de bytes na lista de argumentos (o espaço de pilha necessário). Como resultado, a função é declarada como:

```C
int __stdcall func (int a, double b)
```

é decorado `_func@12` como na saída.

A Convenção de chamada C`__cdecl`() decora o nome como `_func`.

Para obter o nome decorado, use [/MAP](reference/map-generate-mapfile.md). O uso de **__declspec (dllexport)** faz o seguinte:

- Se a função for exportada com a Convenção de`__cdecl`chamada C (), ela retirará **\_** o sublinhado à esquerda () quando o nome for exportado.

- Se a função que está sendo exportada não usar a Convenção de chamada C `__stdcall`(por exemplo,), ela exportará o nome decorado.

Como não há nenhuma maneira de substituir onde a limpeza da pilha ocorre, você deve `__stdcall`usar. Para desdecorar nomes com `__stdcall`o, você deve especificá-los usando aliases na seção EXPORTS do arquivo. def. Isso é mostrado a seguir para a seguinte declaração de função:

```C
int  __stdcall MyFunc (int a, double b);
void __stdcall InitCode (void);
```

No. Arquivo DEF:

```
EXPORTS
   MYFUNC=_MyFunc@12
   INITCODE=_InitCode@0
```

Para que as DLLs sejam chamadas por programas escritos em Visual Basic, a técnica de alias mostrada neste tópico é necessária no arquivo. def. Se o alias for feito no programa de Visual Basic, o uso de alias no arquivo. def não será necessário. Isso pode ser feito no programa de Visual Basic adicionando uma cláusula alias à instrução [declare](/dotnet/visual-basic/language-reference/statements/declare-statement) .

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Exportando a partir de uma DLL](exporting-from-a-dll.md)

- [Exportando de uma DLL usando. Arquivos DEF](exporting-from-a-dll-using-def-files.md)

- [Exportando de uma DLL usando __declspec (dllexport)](exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportando funções do C++ a serem usadas em executáveis da linguagem C](exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Determinar qual método de exportação usar](determining-which-exporting-method-to-use.md)

- [Nomes decorados](reference/decorated-names.md)

## <a name="see-also"></a>Confira também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)
