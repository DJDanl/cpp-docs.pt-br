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
ms.openlocfilehash: 88705b2a33e3eb82043d93c534477fce96849502
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57417565"
---
# <a name="calling-dll-functions-from-visual-basic-applications"></a>Chamando funções DLL a partir de aplicativos Visual Basic

Para aplicativos Visual Basic (ou aplicativos em outras linguagens como Pascal ou Fortran) chamar funções em uma DLL de C/C++, as funções devem ser exportadas usando a convenção de chamada correta sem nenhuma decoração de nome feita pelo compilador

`__stdcall` cria a convenção de chamada correta para a função (a função chamada limpa a pilha e os parâmetros são passados da direita para esquerda), mas adorna o nome da função de maneira diferente. Assim, quando **dllexport** é usado em uma função exportada em uma DLL, o nome decorado é exportado.

O `__stdcall` decoração de nome Prefixa o nome de símbolo com um sublinhado ( **\_** ) e acrescenta o símbolo com um sinal de arroba (**\@**) caractere seguido pelo número de bytes na lista de argumentos (o espaço de pilha necessário). Como resultado, a função quando declarada como:

```C
int __stdcall func (int a, double b)
```

é decorado como `_func@12` na saída.

A convenção de chamada C (`__cdecl`) decora o nome como `_func`.

Para obter o nome decorado, use [/Map](../build/reference/map-generate-mapfile.md). Uso de **dllexport** faz o seguinte:

- Se a função será exportada com a convenção de chamada C (`__cdecl`), ele tira o sublinhado ( **\_** ) quando o nome é exportado.

- Se a função que está sendo exportada não usa a convenção de chamada C (por exemplo, `__stdcall`), ele exporta o nome decorado.

Como não há nenhuma maneira de substituir onde ocorre a limpeza de pilha, você deve usar `__stdcall`. Para os nomes com não decorados `__stdcall`, você deve especificá-los usando aliases na seção de exportações do arquivo. def. Isso é mostrado a seguir para a seguinte declaração de função:

```C
int  __stdcall MyFunc (int a, double b);
void __stdcall InitCode (void);
```

Na. Arquivo DEF:

```
EXPORTS
   MYFUNC=_MyFunc@12
   INITCODE=_InitCode@0
```

Para DLLs sejam chamadas pelos programas escritos em Visual Basic, a técnica do alias exibida neste tópico é necessária no arquivo. def. Se o alias for feito no programa Visual Basic, o uso de serrilhado no arquivo. def não é necessário. Isso pode ser feito no programa Visual Basic, adicionando uma cláusula alias para o [Declare](/dotnet/visual-basic/language-reference/statements/declare-statement) instrução.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Exportando de uma DLL](../build/exporting-from-a-dll.md)

- [Exportando de uma DLL usando. Arquivos DEF](../build/exporting-from-a-dll-using-def-files.md)

- [Exportando a partir de uma DLL usando dllexport](../build/exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportando funções C++ para uso em executáveis da linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Determinando qual método de exportação usar](../build/determining-which-exporting-method-to-use.md)

- [Nomes decorados](../build/reference/decorated-names.md)

## <a name="see-also"></a>Consulte também

[DLLs no Visual C++](../build/dlls-in-visual-cpp.md)
