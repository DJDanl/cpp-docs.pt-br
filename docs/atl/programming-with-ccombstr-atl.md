---
title: Programando com o CComBSTR (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CComBSTR class, programming with
- Unicode, using CComBSTR [ATL]
ms.assetid: d3bd0851-d132-4be9-9c4c-6ccba17acb2b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b957cca4ff1af93d3f62ab0bf667462c91b81bba
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32357851"
---
# <a name="programming-with-ccombstr-atl"></a>Programando com o CComBSTR (ATL)
A classe ATL [CComBSTR](../atl/reference/ccombstr-class.md) fornece um wrapper em torno de `BSTR` tipo de dados. Enquanto `CComBSTR` é uma ferramenta útil, há várias situações que exigem atenção.  
  
-   [Problemas de conversão](#programmingwithccombstr_conversionissues)  
  
-   [Problemas de escopo](#programmingwithccombstr_scopeissues)  
  
-   [Liberando explicitamente o objeto CComBSTR](#programmingwithccombstr_explicitlyfreeing)  
  
-   [Usando CComBSTR objetos em Loops](#programmingwithccombstr_usingloops)  
  
-   [Problemas de vazamento de memória](#programmingwithccombstr_memoryleaks)  
  
##  <a name="programmingwithccombstr_conversionissues"></a> Problemas de conversão  
 Embora várias `CComBSTR` métodos converterá automaticamente um argumento de cadeia de caracteres ANSI em Unicode, os métodos sempre retornará cadeias de caracteres de formato Unicode. Para converter a cadeia de caracteres de saída para ANSI, use uma classe de conversão de ATL. Para obter mais informações sobre as classes de conversão de ATL, consulte [ATL e MFC Macros de conversão de cadeia de caracteres](reference/string-conversion-macros.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#114](../atl/codesnippet/cpp/programming-with-ccombstr-atl_1.cpp)]  
  
 Se você estiver usando uma cadeia de caracteres literal para modificar um `CComBSTR` de objeto, use cadeias de caractere largo. Isso reduzirá conversões desnecessárias.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#115](../atl/codesnippet/cpp/programming-with-ccombstr-atl_2.cpp)]  
  
##  <a name="programmingwithccombstr_scopeissues"></a> Problemas de escopo  
 Assim como acontece com qualquer classe com bom comportamento, `CComBSTR` irá liberar seus recursos quando ele sai do escopo. Se uma função retorna um ponteiro para o `CComBSTR` cadeia de caracteres, isso pode causar problemas, como o ponteiro fará referência a memória já foi liberada. Nesses casos, use o **cópia** método, conforme mostrado abaixo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#116](../atl/codesnippet/cpp/programming-with-ccombstr-atl_3.cpp)]  
  
##  <a name="programmingwithccombstr_explicitlyfreeing"></a> Liberando explicitamente o objeto CComBSTR  
 É possível liberar explicitamente a cadeia de caracteres dentro de `CComBSTR` antes do objeto sai do escopo do objeto. Se a cadeia de caracteres é liberada, o `CComBSTR` o objeto é inválido.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#117](../atl/codesnippet/cpp/programming-with-ccombstr-atl_4.cpp)]  
  
##  <a name="programmingwithccombstr_usingloops"></a> Usando CComBSTR objetos em Loops  
 Como o `CComBSTR` classe aloca um buffer para executar determinadas operações, como o `+=` operador ou **Append** método, não é recomendável que você executar a manipulação de cadeia de caracteres dentro de um loop estreito. Nessas situações, `CStringT` oferece um melhor desempenho.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#118](../atl/codesnippet/cpp/programming-with-ccombstr-atl_5.cpp)]  
  
##  <a name="programmingwithccombstr_memoryleaks"></a> Problemas de vazamento de memória  
 Passe o endereço de uma inicializado `CComBSTR` para uma função como um **[out]** parâmetro faz com que um vazamento de memória.  
  
 No exemplo a seguir, a cadeia de caracteres alocada para armazenar a cadeia de caracteres `"Initialized"` vazou quando a função `MyGoodFunction` substitui a cadeia de caracteres.  
  
 [!code-cpp[NVC_ATL_Utilities#119](../atl/codesnippet/cpp/programming-with-ccombstr-atl_6.cpp)]  
  
 Para evitar o vazamento, chame o **vazio** método existente `CComBSTR` objetos antes de passar o endereço como um **[out]** parâmetro.  
  
 Observe que o mesmo código não causará um vazamento de se o parâmetro da função foi **[no, out]**.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)   
 [Classe CStringT](../atl-mfc-shared/reference/cstringt-class.md)   
 [wstring](../standard-library/basic-string-class.md)   
 [Macros de conversão de cadeia de caracteres](../atl/reference/string-conversion-macros.md)

