---
title: "Operações CString básicas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- CString objects, basic operations
- string literals, CString operations
- literal strings, CString operations
- CString objects
- string comparison, CString operations
- characters, accessing in CStrings
ms.assetid: 41db66b2-9427-4bb3-845a-9b6869159a6c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 42353a9c59bead96da8eb3b114c8acb2361b53d0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="basic-cstring-operations"></a>Operações CString básicas
Este tópico explica o seguinte basic [CString](../atl-mfc-shared/reference/cstringt-class.md) operações:  
  
- [Criando objetos CString de padrão C cadeias de caracteres literais](#_core_creating_cstring_objects_from_standard_c_literal_strings)  
  
- [Acessando caracteres individuais em um CString](#_core_accessing_individual_characters_in_a_cstring)  
  
- [Concatenação de dois objetos CString](#_core_concatenating_two_cstring_objects)  
  
- [Comparando objetos CString](#_core_comparing_cstring_objects)  
  
- [Convertendo objetos CString](#_core_converting_cstring_objects)  
  
 `Class CString`baseado no modelo de classe [CStringT classe](../atl-mfc-shared/reference/cstringt-class.md). `CString`é um `typedef` de `CStringT`. Mais exatamente, `CString` é um `typedef` de um *especialização explícita* de `CStringT`, que é uma maneira comum de usar um modelo de classe para definir uma classe. Classes da mesma forma definidas são `CStringA` e `CStringW`.  
  
 `CString`, `CStringA`, e `CStringW` são definidos em atlstr.h. `CStringT`é definido em cstringt.h.  
  
 `CString`, `CStringA`, e `CStringW` cada obter um conjunto de métodos e operadores definidos pelo `CStringT` para uso com os dados de cadeia de caracteres que eles oferecem suporte. Alguns dos métodos duplicados e, em alguns casos, ultrapassam os serviços de cadeia de caracteres das bibliotecas de tempo de execução do C.  
  
 Observação: `CString` é uma classe nativo. Para uma classe de cadeia de caracteres que é para uso em C + + CLI gerenciados projeto, use `System.String`.  
  
##  <a name="_core_creating_cstring_objects_from_standard_c_literal_strings"></a>Criando objetos CString de cadeias de caracteres Literal C padrão  
 Você pode atribuir cadeias de caracteres literais de estilo C um `CString` assim como você pode atribuir uma `CString` objeto para outro.  
  
-   Atribuir o valor de uma cadeia de caracteres literal C para um `CString` objeto.  
  
 [!code-cpp[NVC_ATLMFC_Utilities#183](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_1.cpp)]  
  
-   Atribuir o valor de um `CString` para outro `CString` objeto.  
  
 [!code-cpp[NVC_ATLMFC_Utilities#184](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_2.cpp)]  
  
     O conteúdo de um `CString` objeto são copiadas quando um `CString` objeto é atribuído a outro. Portanto, as duas cadeias de caracteres não compartilham uma referência para os caracteres reais que compõem a cadeia de caracteres. Para obter mais informações sobre como usar `CString` objetos como valores, consulte [semântica de CString](../atl-mfc-shared/cstring-semantics.md).  
  
    > [!NOTE]
    >  Para gravar seu aplicativo para que ele pode ser compilado para Unicode ou ANSI, código de cadeias de caracteres literais usando a macro t. Para obter mais informações, consulte [suporte a Unicode e conjunto de caracteres Multibyte (MBCS)](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md).  
  
##  <a name="_core_accessing_individual_characters_in_a_cstring"></a>Acessando caracteres individuais em um CString  
 Você pode acessar caracteres individuais em um `CString` objeto usando o `GetAt` e `SetAt` métodos. Você também pode usar o elemento ou subscrito, operador de matriz ([]), em vez de `GetAt` obter caracteres individuais. (Isso é semelhante a acessar elementos de matriz por índice, como cadeias de caracteres de estilo C padrão.) Valores de índice `CString` caracteres são baseadas em zero.  
  
##  <a name="_core_concatenating_two_cstring_objects"></a>Concatenação de dois objetos CString  
 Para concatenar duas `CString` objetos, use os operadores de concatenação (+ ou + =), da seguinte maneira.  
  
 [!code-cpp[NVC_ATLMFC_Utilities#185](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_3.cpp)]  
  
 Pelo menos um argumento para os operadores de concatenação (+ ou + =) deve ser um `CString` objeto, mas você pode usar uma cadeia de caracteres constante (por exemplo, `"big"`) ou um `char` (por exemplo, ' x') para o outro argumento.  
  
##  <a name="_core_comparing_cstring_objects"></a>Comparando objetos CString  
 O `Compare` método e o operador para = = `CString` são equivalentes. `Compare`, `operator==`, e `CompareNoCase` reconhecem Unicode e MBCS; `CompareNoCase` também diferencia maiusculas de minúsculas. O `Collate` método `CString` é com distinção de localidade e costuma ser mais lento do que `Compare`. Use `Collate` somente onde você deve concordar com a classificação regras conforme especificado pela localidade atual.  
  
 A tabela a seguir mostra o disponíveis [CString](../atl-mfc-shared/reference/cstringt-class.md) funções de comparação e suas funções MBCS/Unicode-portáteis equivalentes na biblioteca de tempo de execução do C.  
  
|Função CString|Função MBCS|Função Unicode|  
|----------------------|-------------------|----------------------|  
|`Compare`|`_mbscmp`|`wcscmp`|  
|`CompareNoCase`|`_mbsicmp`|`_wcsicmp`|  
|`Collate`|`_mbscoll`|`wcscoll`|  
  
 O `CStringT` template de classe define os operadores relacionais (<, \<=, > =, >, = =, e! =), que estão disponíveis para uso por `CString`. Você pode comparar dois `CStrings` usando esses operadores, como mostrado no exemplo a seguir.  
  
 [!code-cpp[NVC_ATLMFC_Utilities#186](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_4.cpp)]  
  
##  <a name="_core_converting_cstring_objects"></a>Convertendo objetos CString  
 Para obter informações sobre como converter objetos CString em outros tipos de cadeia de caracteres, consulte [como: converter entre vários tipos de cadeia de caracteres](../text/how-to-convert-between-various-string-types.md).  
  
## <a name="using-cstring-with-wcout"></a>Usando CString com wcout  
 Para usar um CString com `wcout` é necessário converter explicitamente o objeto para um `const wchar_t*` conforme mostrado no exemplo a seguir:  
  
```  
CString cs("meow");

    wcout <<(const wchar_t*) cs <<endl;  
 
```  
  
 Sem a conversão, `cs` é tratado como um `void*` e `wcout` imprime o endereço do objeto. Esse comportamento é causado por sutis interações entre o modelo argumento dedução e sobrecarga de resolução que estão em si correto e em conformidade com o padrão do C++.  
  
## <a name="see-also"></a>Consulte também  
 [Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)   
 [Classe CStringT](../atl-mfc-shared/reference/cstringt-class.md)   
 [Especialização de modelo](../cpp/template-specialization-cpp.md)   
 [Como converter entre diversos tipos de cadeias de caracteres](../text/how-to-convert-between-various-string-types.md)

