---
title: "Opera&#231;&#245;es b&#225;sicas de CString | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "caracteres, acessar em CStrings"
  - "Objetos de CString"
  - "Objetos de CString, operações básicas"
  - "cadeias de caracteres literais, Operações de CString"
  - "comparação de cadeias de caracteres, Operações de CString"
  - "literais de cadeia de caracteres, Operações de CString"
ms.assetid: 41db66b2-9427-4bb3-845a-9b6869159a6c
caps.latest.revision: 17
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Opera&#231;&#245;es b&#225;sicas de CString
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico explica as seguintes operações básicas de [CString](../atl-mfc-shared/reference/cstringt-class.md) :  
  
-   [Criando objetos de CString de cadeias de caracteres literal padrões de C](#_core_creating_cstring_objects_from_standard_c_literal_strings)  
  
-   [Acessando caracteres individuais em um CString](#_core_accessing_individual_characters_in_a_cstring)  
  
-   [Concatenando dois objetos de CString](#_core_concatenating_two_cstring_objects)  
  
-   [Comparando objetos de CString](#_core_comparing_cstring_objects)  
  
-   [Convertendo objetos de CString](#_core_converting_cstring_objects)  
  
 `Class CString` é baseado no modelo [Classe de CStringT](../atl-mfc-shared/reference/cstringt-class.md)da classe.  `CString` é `typedef` de `CStringT`.  Mais precisamente, `CString` é `typedef`*de uma especialização explícita* de `CStringT`, que é uma maneira comum de usar um modelo da classe para definir uma classe.  As classes da mesma forma são definidas `CStringA` e `CStringW`.  Para obter mais informações sobre a especialização explícita, consulte [Instanciação do modelo de classe](../Topic/Class%20Template%20Instantiation.md).  
  
 `CString`, `CStringA`, e `CStringW` são definidos em atlstr.h.  `CStringT` é definido em cstringt.h.  
  
 `CString`, `CStringA`, e cada um `CStringW` obtém um conjunto de métodos e dos operadores definido por `CStringT` para uso com os dados de cadeia de caracteres suporta.  Qualquer duplicadas dos métodos e, em alguns casos, ultrapassa os serviços de cadeia de caracteres das bibliotecas em tempo de execução de C.  
  
 Observação: `CString` é uma classe nativo.  Para uma classe de cadeia de caracteres que é para uso no projeto gerenciado \+\+\/CLI de energia AC, use `System.String`.  
  
##  <a name="_core_creating_cstring_objects_from_standard_c_literal_strings"></a> Criando objetos de CString de cadeias de caracteres literal padrões de C  
 Você pode atribuir cadeias de caracteres literais ctype \-\- estilo a `CString` assim como você pode atribuir um objeto de `CString` para outro.  
  
-   Atribua o valor da cadeia de caracteres literal de energia AC a um objeto de `CString` .  
  
     [!code-cpp[NVC_ATLMFC_Utilities#183](../atl-mfc-shared/codesnippet/CPP/basic-cstring-operations_1.cpp)]  
  
-   Atribua o valor de um `CString` a outro objeto de `CString` .  
  
     [!code-cpp[NVC_ATLMFC_Utilities#184](../atl-mfc-shared/codesnippet/CPP/basic-cstring-operations_2.cpp)]  
  
     O conteúdo de um objeto de `CString` são copiados quando um objeto de `CString` é atribuído ao outro.  Portanto, as duas cadeias de caracteres não compartilham uma referência para caracteres reais que compõem a cadeia de caracteres.  Para obter mais informações sobre como usar objetos de `CString` como valores, consulte [Semântica de CString](../atl-mfc-shared/cstring-semantics.md).  
  
    > [!NOTE]
    >  Para escrever seu aplicativo para que ele pode ser compilado para ANSI, Unicode ou para cadeias de caracteres literais de código usando a macro de \_T.  Para mais informações, consulte [Suporte a Unicode e Multibyte Character Set \(MBCS\)](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md).  
  
##  <a name="_core_accessing_individual_characters_in_a_cstring"></a> Acessando caracteres individuais em um CString  
 Você pode acessar caracteres individuais em um objeto de `CString` usando os métodos e de `GetAt` de `SetAt` .  Você também pode usar o elemento da matriz, ou subscrito, o operador \(\[ \]\) em vez de `GetAt` para obter caracteres individuais.  \(Isso se assemelha a acessar elementos pelo índice de matriz, como em cadeias de caracteres de estilo \-\- C.\) Os valores de índice de caracteres de `CString` são baseados em zero.  
  
##  <a name="_core_concatenating_two_cstring_objects"></a> Concatenando dois objetos de CString  
 Para concatenar dois objetos de `CString` , use os operadores de concatenação \(\+\) ou \+\=, como segue.  
  
 [!code-cpp[NVC_ATLMFC_Utilities#185](../atl-mfc-shared/codesnippet/CPP/basic-cstring-operations_3.cpp)]  
  
 Por o menos um argumento para os operadores de concatenação \(\+\) ou \+\= deve ser um objeto de `CString` , mas você pode usar uma cadeia de caracteres constante \(por exemplo, `"big"`\) ou um `char` \(por exemplo, “x "\) para o outro argumento.  
  
##  <a name="_core_comparing_cstring_objects"></a> Comparando objetos de CString  
 O método de `Compare` e o operador de \=\= para `CString` são equivalentes.  `Compare`, `operator==`, e `CompareNoCase` são MBCS e Unicode cientes; `CompareNoCase` também é não diferencia maiúsculas de minúsculas.  O método de `Collate` de `CString` é sensível e são geralmente é mais lento do que `Compare`.  Use `Collate` apenas onde você deve seguir as regras de classificação conforme especificado pela localidade atual.  
  
 A tabela a seguir mostra as funções disponíveis de comparação de [CString](../atl-mfc-shared/reference/cstringt-class.md) e suas funções do equivalente Unicode\/MBCS\-portable na biblioteca em tempo de execução de C.  
  
|Função de CString|função MBCS|Função Unicode|  
|-----------------------|-----------------|--------------------|  
|`Compare`|`_mbscmp`|`wcscmp`|  
|`CompareNoCase`|`_mbsicmp`|`_wcsicmp`|  
|`Collate`|`_mbscoll`|`wcscoll`|  
  
 O modelo de classe de `CStringT` define os operadores relacionais \(\<, \<\=, \>\=, \>, \=\=, e\! \=\), que estão disponíveis para uso de `CString`.  Você pode comparar dois `CStrings` usando esses operadores, conforme mostrado no exemplo o seguir.  
  
 [!code-cpp[NVC_ATLMFC_Utilities#186](../atl-mfc-shared/codesnippet/CPP/basic-cstring-operations_4.cpp)]  
  
##  <a name="_core_converting_cstring_objects"></a> Convertendo objetos de CString  
 Para obter informações sobre como converter objetos de CString a outros tipos de cadeia de caracteres, consulte [Como converter entre diversos tipos de cadeia de caracteres](../Topic/How%20to:%20Convert%20Between%20Various%20String%20Types.md).  
  
## Usando CString com wcout  
 Para usar um CString com `wcout` você deve converter explicitamente o objeto a `const wchar_t*` conforme mostrado no exemplo o seguir:  
  
```  
CString cs("meow");  
  wcout << (const wchar_t*) cs << endl;  
  
```  
  
 Sem a conversão, `cs` é tratado como `void*` e `wcout` imprimem o endereço do objeto.  Esse comportamento é causado pelas interações entre a sutis dedução do argumento do modelo e a resolução de sobrecarga que estão em se corretos e conformes com o padrão C\+\+.  
  
## Consulte também  
 [Cadeias de caracteres](../atl-mfc-shared/strings-atl-mfc.md)   
 [Classe de CStringT](../atl-mfc-shared/reference/cstringt-class.md)   
 [Instanciação do modelo de classe](../Topic/Class%20Template%20Instantiation.md)   
 [Especialização explícita de modelos de classe](../Topic/Explicit%20Specialization%20of%20Class%20Templates.md)   
 [Especialização parcial de modelos de classe](../cpp/template-specialization-cpp.md)   
 [Como converter entre diversos tipos de cadeia de caracteres](../Topic/How%20to:%20Convert%20Between%20Various%20String%20Types.md)