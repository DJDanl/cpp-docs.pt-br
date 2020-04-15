---
title: Programando com o CComBSTR (ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- CComBSTR class, programming with
- Unicode, using CComBSTR [ATL]
ms.assetid: d3bd0851-d132-4be9-9c4c-6ccba17acb2b
ms.openlocfilehash: 020c2d18c721e658d15bb1451039154ae50b99f6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321789"
---
# <a name="programming-with-ccombstr-atl"></a>Programando com o CComBSTR (ATL)

A classe [ATL CComBSTR](../atl/reference/ccombstr-class.md) fornece um invólucro em torno do tipo de dados BSTR. Embora `CComBSTR` seja uma ferramenta útil, existem várias situações que requerem cautela.

- [Problemas de conversão](#programmingwithccombstr_conversionissues)

- [Problemas de escopo](#programmingwithccombstr_scopeissues)

- [Liberando explicitamente o objeto CComBSTR](#programmingwithccombstr_explicitlyfreeing)

- [Usando objetos CComBSTR em loops](#programmingwithccombstr_usingloops)

- [Problemas de vazamento de memória](#programmingwithccombstr_memoryleaks)

## <a name="conversion-issues"></a><a name="programmingwithccombstr_conversionissues"></a>Problemas de conversão

Embora `CComBSTR` vários métodos convertam automaticamente um argumento de seqüência ANSI em Unicode, os métodos sempre retornarão strings de formato Unicode. Para converter a seqüência de saída de volta para ANSI, use uma classe de conversão ATL. Para obter mais informações sobre as classes de conversão ATL, consulte [Macros de conversão de strings ATL e MFC](reference/string-conversion-macros.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#114](../atl/codesnippet/cpp/programming-with-ccombstr-atl_1.cpp)]

Se você estiver usando uma `CComBSTR` seqüência literal para modificar um objeto, use strings de caractere sumidos. Isso reduzirá conversões desnecessárias.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#115](../atl/codesnippet/cpp/programming-with-ccombstr-atl_2.cpp)]

## <a name="scope-issues"></a><a name="programmingwithccombstr_scopeissues"></a>Problemas de escopo

Como em qualquer classe bem `CComBSTR` comportada, liberará seus recursos quando sair do escopo. Se uma função retornar `CComBSTR` um ponteiro para a seqüência, isso pode causar problemas, pois o ponteiro fará referência à memória que já foi liberada. Nestes casos, `Copy` utilize o método, como mostrado abaixo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#116](../atl/codesnippet/cpp/programming-with-ccombstr-atl_3.cpp)]

## <a name="explicitly-freeing-the-ccombstr-object"></a><a name="programmingwithccombstr_explicitlyfreeing"></a>Liberando explicitamente o objeto CComBSTR

É possível liberar explicitamente a seqüência contida no `CComBSTR` objeto antes que o objeto saia do escopo. Se a seqüência `CComBSTR` for liberada, o objeto será inválido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#117](../atl/codesnippet/cpp/programming-with-ccombstr-atl_4.cpp)]

## <a name="using-ccombstr-objects-in-loops"></a><a name="programmingwithccombstr_usingloops"></a>Usando objetos CComBSTR em loops

Como `CComBSTR` a classe aloca um buffer para executar `+=` determinadas operações, como o operador ou `Append` o método, não é recomendável que você execute a manipulação de cordas dentro de um loop apertado. Nessas situações, `CStringT` proporciona melhor desempenho.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#118](../atl/codesnippet/cpp/programming-with-ccombstr-atl_5.cpp)]

## <a name="memory-leak-issues"></a><a name="programmingwithccombstr_memoryleaks"></a>Problemas de vazamento de memória

Passar o endereço de `CComBSTR` uma função inicializada para uma função como um parâmetro **[out]** causa um vazamento de memória.

No exemplo abaixo, a seqüência `"Initialized"` alocada para segurar `MyGoodFunction` a seqüência é vazada quando a função substitui a string.

[!code-cpp[NVC_ATL_Utilities#119](../atl/codesnippet/cpp/programming-with-ccombstr-atl_6.cpp)]

Para evitar o vazamento, ligue para o `Empty` método em objetos existentes `CComBSTR` antes de passar o endereço como um parâmetro **[out].**

Observe que o mesmo código não causaria um vazamento se o parâmetro da função estivesse **[dentro, fora]**.

## <a name="see-also"></a>Confira também

[Conceitos](../atl/active-template-library-atl-concepts.md)<br/>
[Classe Cstringt](../atl-mfc-shared/reference/cstringt-class.md)<br/>
[wstring](../standard-library/basic-string-class.md)<br/>
[Macros de conversão de strings](../atl/reference/string-conversion-macros.md)
