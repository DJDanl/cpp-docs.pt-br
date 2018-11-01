---
title: Programando com o CComBSTR (ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- CComBSTR class, programming with
- Unicode, using CComBSTR [ATL]
ms.assetid: d3bd0851-d132-4be9-9c4c-6ccba17acb2b
ms.openlocfilehash: 44689b45d567c524d6db1446cd65201c21499c91
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50633110"
---
# <a name="programming-with-ccombstr-atl"></a>Programando com o CComBSTR (ATL)

A classe ATL [CComBSTR](../atl/reference/ccombstr-class.md) fornece um wrapper em torno do tipo de dados BSTR. Enquanto `CComBSTR` é uma ferramenta útil, há várias situações que exigem atenção.

- [Problemas de conversão](#programmingwithccombstr_conversionissues)

- [Problemas de escopo](#programmingwithccombstr_scopeissues)

- [Liberando explicitamente o objeto CComBSTR](#programmingwithccombstr_explicitlyfreeing)

- [Usando CComBSTR objetos em Loops](#programmingwithccombstr_usingloops)

- [Problemas de vazamento de memória](#programmingwithccombstr_memoryleaks)

##  <a name="programmingwithccombstr_conversionissues"></a> Problemas de conversão

Embora vários `CComBSTR` métodos converterá automaticamente um argumento de cadeia de caracteres ANSI em Unicode, os métodos sempre retornará cadeias de caracteres de formato Unicode. Para converter a cadeia de caracteres de saída para ANSI, use uma classe de conversão ATL. Para obter mais informações sobre as classes de conversão ATL, consulte [ATL e Macros de conversão de cadeia de caracteres MFC](reference/string-conversion-macros.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#114](../atl/codesnippet/cpp/programming-with-ccombstr-atl_1.cpp)]

Se você estiver usando um literal de cadeia de caracteres para modificar um `CComBSTR` de objeto, use cadeias de caracteres largos. Isso reduzirá as conversões desnecessárias.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#115](../atl/codesnippet/cpp/programming-with-ccombstr-atl_2.cpp)]

##  <a name="programmingwithccombstr_scopeissues"></a> Problemas de escopo

Assim como acontece com qualquer classe bem comportado, `CComBSTR` irá liberar seus recursos quando ele sai do escopo. Se uma função retorna um ponteiro para o `CComBSTR` cadeia de caracteres, isso pode causar problemas, como o ponteiro fará referência a memória já foi liberada. Nesses casos, use o `Copy` método, conforme mostrado abaixo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#116](../atl/codesnippet/cpp/programming-with-ccombstr-atl_3.cpp)]

##  <a name="programmingwithccombstr_explicitlyfreeing"></a> Liberando explicitamente o objeto CComBSTR

É possível liberar explicitamente a cadeia de caracteres contida no `CComBSTR` antes do objeto sai do escopo do objeto. Se a cadeia de caracteres é liberada, o `CComBSTR` objeto é inválido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#117](../atl/codesnippet/cpp/programming-with-ccombstr-atl_4.cpp)]

##  <a name="programmingwithccombstr_usingloops"></a> Usando CComBSTR objetos em Loops

Como o `CComBSTR` classe aloca um buffer para executar determinadas operações, como o `+=` operador ou `Append` método, não é recomendável que você executar a manipulação de cadeia de caracteres dentro de um loop estreito. Nessas situações, `CStringT` fornece um melhor desempenho.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#118](../atl/codesnippet/cpp/programming-with-ccombstr-atl_5.cpp)]

##  <a name="programmingwithccombstr_memoryleaks"></a> Problemas de vazamento de memória

Passar o endereço de um inicializado `CComBSTR` para uma função como uma **[out]** parâmetro faz com que um vazamento de memória.

No exemplo a seguir, a cadeia de caracteres alocado para manter a cadeia de caracteres `"Initialized"` é perdido quando a função `MyGoodFunction` substitui a cadeia de caracteres.

[!code-cpp[NVC_ATL_Utilities#119](../atl/codesnippet/cpp/programming-with-ccombstr-atl_6.cpp)]

Para evitar o vazamento, chame o `Empty` método existente `CComBSTR` objetos antes de passar o endereço como um **[out]** parâmetro.

Observe que o mesmo código não causará um vazamento de se o parâmetro da função tiver sido **[em, out]**.

## <a name="see-also"></a>Consulte também

[Conceitos](../atl/active-template-library-atl-concepts.md)<br/>
[Classe CStringT](../atl-mfc-shared/reference/cstringt-class.md)<br/>
[wstring](../standard-library/basic-string-class.md)<br/>
[Macros de conversão de cadeia de caracteres](../atl/reference/string-conversion-macros.md)

