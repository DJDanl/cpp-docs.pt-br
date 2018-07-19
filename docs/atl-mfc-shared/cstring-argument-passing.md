---
title: Passagem de argumento CString | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- strings [C++], as function input/output
- argument passing [C++]
- arguments [C++], passing
- functions [C++], strings as input/output
- argument passing [C++], C strings
- passing arguments, C strings
- CString objects, passing arguments
- string arguments
ms.assetid: a67bebff-edf1-4cf4-bbff-d1cc6a901099
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 86e89a0f4af28606abef8804aeab5d1e2f62e8d8
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37882445"
---
# <a name="cstring-argument-passing"></a>Passagem de argumento CString
Este artigo explica como passar [CString](../atl-mfc-shared/reference/cstringt-class.md) objetos para funções e como retornar `CString` objetos de funções.  
  
##  <a name="_core_cstring_argument.2d.passing_conventions"></a> Convenções de passagem de argumento de CString  
 Quando você define uma interface de classe, você deve determinar a convenção de passagem de argumentos para suas funções de membro. Há algumas regras padrão para passar e retornar `CString` objetos. Se você seguir as regras descritas em [cadeias de caracteres como entradas de função](#_core_strings_as_function_inputs) e [cadeias de caracteres como saídas da função](#_core_strings_as_function_outputs), você terá um código correto e eficiente.  
  
##  <a name="_core_strings_as_function_inputs"></a> Cadeias de caracteres como entradas de função  
 Maneira mais eficiente e segura usar um `CString` objeto nas funções chamadas é passar um `CString` objeto para a função. Apesar do nome, um `CString` objeto não armazena uma cadeia de caracteres internamente como uma cadeia de caracteres de estilo C que tem um terminador nulo. Em vez disso, um `CString` objeto cuidado controla o número de caracteres que ele tem. Tendo `CString` fornecem um ponteiro LPCTSTR para uma cadeia de caracteres terminada em nulo é uma pequena quantidade de trabalho que pode se tornar significativa se seu código tem de fazê-lo constantemente. O resultado é temporário, pois qualquer alteração de `CString` conteúdo invalida as cópias antigas do ponteiro LPCTSTR.  
  
 Faz sentido em alguns casos para fornecer uma cadeia de caracteres de estilo C. Por exemplo, pode haver uma situação em que uma função chamada é escrita em C e não oferece suporte a objetos. Nesse caso, forçar o `CString` parâmetro LPCTSTR e a função obterá uma cadeia de caracteres do estilo C terminada em nulo. Você também pode ir na outra direção e criar uma `CString` objeto usando o `CString` construtor que aceita um parâmetro de cadeia de caracteres de estilo C.  
  
 Se o conteúdo de cadeia de caracteres devem ser alteradas por uma função, declare o parâmetro como um nonconstant `CString` referência (`CString&`).  
  
##  <a name="_core_strings_as_function_outputs"></a> Cadeias de caracteres como saídas da função  
 Normalmente, você pode retornar `CString` objetos de funções porque `CString` objetos seguem a semântica de valor, como tipos primitivos. Para retornar uma cadeia de caracteres somente leitura, use uma constante `CString` referência (`const CString&`). O exemplo a seguir ilustra o uso de `CString` parâmetros e tipos de retorno:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#197](../atl-mfc-shared/codesnippet/cpp/cstring-argument-passing_1.cpp)]  
  
 [!code-cpp[NVC_ATLMFC_Utilities#198](../atl-mfc-shared/codesnippet/cpp/cstring-argument-passing_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)

