---
title: Passagem de argumento CString | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs: C++
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
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3d33c8cc46ada41f851c90aaae0cabfadb1466d0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cstring-argument-passing"></a>Passagem de argumento CString
Este artigo explica como passar [CString](../atl-mfc-shared/reference/cstringt-class.md) objetos para funções e como retornar `CString` objetos de funções.  
  
##  <a name="_core_cstring_argument.2d.passing_conventions"></a>Convenções de passagem de argumento CString  
 Quando você define uma interface de classe, você deve determinar a convenção de passagem de argumento para as funções de membro. Existem algumas regras padrão para passar e retornando `CString` objetos. Se você seguir as regras descritas [cadeias de caracteres como entradas de função](#_core_strings_as_function_inputs) e [cadeias de caracteres como saídas de função](#_core_strings_as_function_outputs), você terá de código correto e eficiente.  
  
##  <a name="_core_strings_as_function_inputs"></a>Cadeias de caracteres como entradas de função  
 Maneira mais eficiente e segura para usar um `CString` objeto em funções de chamada é passar uma `CString` objeto para a função. Apesar do nome, um `CString` objeto não armazena uma cadeia de caracteres internamente como uma cadeia de caracteres de estilo C com um terminador nulo. Em vez disso, um `CString` objeto cuidado rastreia o número de caracteres que ele tem. Tendo `CString` fornecem um `LPCTSTR` ponteiro para uma cadeia de caracteres terminada em nulo é uma pequena quantidade de trabalho que pode se tornar significativo se o seu código precisa fazê-lo constantemente. O resultado é temporário, pois qualquer alteração de `CString` conteúdo invalida as cópias antigas do `LPCTSTR` ponteiro.  
  
 Isso faz sentido em alguns casos para fornecer uma cadeia de caracteres de estilo C. Por exemplo, pode haver uma situação em que uma função chamada é escrita em C e não dá suporte a objetos. Nesse caso, forçar o `CString` parâmetro `LPCTSTR`, e a função obterá uma cadeia de caracteres terminada em nulo do estilo C. Você também pode ir na outra direção e criar um `CString` objeto usando o `CString` construtor que aceita um parâmetro de cadeia de caracteres de estilo C.  
  
 Se o conteúdo de cadeia de caracteres devem ser alteradas por uma função, declare o parâmetro como um nonconstant `CString` referência (**CString &**).  
  
##  <a name="_core_strings_as_function_outputs"></a>Cadeias de caracteres como saídas de função  
 Normalmente, você pode retornar `CString` objetos de funções porque `CString` objetos seguem a semântica de valor como tipos primitivos. Para retornar uma cadeia de caracteres somente leitura, use uma constante `CString` referência (**const CString &**). O exemplo a seguir ilustra o uso de `CString` parâmetros e tipos de retorno:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#197](../atl-mfc-shared/codesnippet/cpp/cstring-argument-passing_1.cpp)]  
  
 [!code-cpp[NVC_ATLMFC_Utilities#198](../atl-mfc-shared/codesnippet/cpp/cstring-argument-passing_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)

