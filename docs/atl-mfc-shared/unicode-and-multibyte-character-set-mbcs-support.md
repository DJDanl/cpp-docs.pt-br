---
title: "Suporte a Unicode e Multibyte Character Set (MBCS) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
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
  - "Conjunto de caracteres MFC [C++], suporte"
  - "Suporte MBCS [C++], cadeias de caracteres e MFC"
  - "cadeias de caracteres [C++], suporte de MBCS no MFC"
  - "conjuntos de caracteres [C++] multibyte"
  - "Unicode [C++], seqüências de caracteres MFC"
  - "Unicode [C++], objetos de cadeia de caracteres"
  - "cadeias de caracteres [C++], Unicode"
  - "conjunto de caracteres de cadeias de caracteres [C++], suporte"
ms.assetid: 44b3193b-c92d-40c5-9fa8-5774da303cce
caps.latest.revision: 17
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Suporte a Unicode e Multibyte Character Set (MBCS)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Algumas linguagens, por exemplo, chinês, japonês e têm grandes conjuntos de caracteres.  Para programação de suporte para esses mercados, a biblioteca de classes da Microsoft foundation \(MFC\) é ativada para duas abordagens diferentes para manipular grandes conjuntos de caracteres:  
  
-   [Unicode](#_core_mfc_support_for_unicode_strings)  
  
-   [Conjuntos de caracteres de Multibyte \(MBCS\)](#_core_mfc_support_for_mbcs_strings)  
  
 Você deve usar Unicode para qualquer desenvolvimento.  
  
##  <a name="_core_mfc_support_for_unicode_strings"></a> Suporte MFC para cadeias de caracteres Unicode  
 A biblioteca de classe inteira é ativada condicional para caracteres e cadeias de caracteres Unicode.  Em particular, a classe [CString](../atl-mfc-shared/reference/cstringt-class.md) atvidades para unicode é ativada.  
  
|||||  
|-|-|-|-|  
|UAFXCW.LIB|UAFXCW.PDB|UAFXCWD.LIB|UAFXCWD.PDB|  
|MFC*xx*U.LIB|MFC*xx*U.PDB|MFC*xx*U.DLL|MFC*xx*UD.LIB|  
|MFC*xx*UD.PDB|MFC*xx*UD.DLL|MFCS*xx*U.LIB|MFCS*xx*U.PDB|  
|MFCS*xx*UD.LIB|MFCS*xx*UD.PDB|MFCM*xx*U.LIB|MFCM*xx*U.PDB|  
|MFCM*xx*U.DLL|MFCM*xx*UD.LIB|MFCM*xx*UD.PDB|MFCM*xx*UD.DLL|  
  
 \(*xx* representa o número de versão do arquivo; por exemplo, “80 " significam a versão 8,0\).  
  
 `CString` é baseado no tipo de dados de `TCHAR` .  Se o símbolo `_UNICODE` é definido para uma compilação do seu programa, `TCHAR` está definido como o tipo `wchar_t`, um tipo de 16 bits de codificação de caracteres.  Caso contrário, `TCHAR` é definido como `char`, a codificação de caracteres de 8 bits normal.  Portanto, em Unicode, `CString` é composta de caracteres de 16 bits.  Sem Unicode, é composto de caracteres de tipo `char`.  
  
 Para concluir a programação Unicode do seu aplicativo, você também deve:  
  
-   Use a macro de `_T` ao código condicional cadeias de caracteres literal para ser portátil a Unicode.  
  
-   Quando você passar cadeias de caracteres, atenção de pagamento a se os argumentos de função requer um comprimento em caracteres ou um tamanho em bytes.  A diferença é importante se você estiver usando cadeias de caracteres Unicode.  
  
-   Use versões portáteis funções de cadeia de caracteres\- manipulação de tempo de execução de C.  
  
-   Use os seguintes tipos de dados para caracteres e ponteiros de caracteres:  
  
    -   `TCHAR` onde você usaria `char`.  
  
    -   `LPTSTR` onde você usaria `char*`.  
  
    -   `LPCTSTR` onde você usaria `const char*`.  `CString` fornece o operador `LPCTSTR` para converter entre `CString` e `LPCTSTR`.  
  
 `CString` também fornece construtores, operadores de atribuição, e operadores de comparação cientes.  
  
 Para informações relacionadas em Unicode que programa, consulte [Tópicos Unicode](../mfc/unicode-in-mfc.md).  [Referência da biblioteca em tempo de execução](../c-runtime-library/c-run-time-library-reference.md) define versões portáteis de todas as suas funções de cadeia de caracteres\- tratamento.  Consulte a categoria [Internacionalização](../c-runtime-library/internationalization.md).  
  
##  <a name="_core_mfc_support_for_mbcs_strings"></a> Suporte MFC para cadeias de caracteres de MBCS  
  
> [!WARNING]
>  As cadeias de caracteres de MBCS são tecnologia herdado e não devem ser usados em novos projetos.  As seguintes informações são fornecidas para cenários em que você precisa manter o código existente que usa MBCS e não é viável atualizar o código para usar Unicode.  
  
 A biblioteca de classes é ativada também para conjuntos de caracteres de multibyte, mas somente para conjuntos de caracteres de dois bytes \(DBCS\).  
  
> [!IMPORTANT]
>  Em [!INCLUDE[vs_dev12](../atl-mfc-shared/includes/vs_dev12_md.md)] e posterior, as versões de MBCS de DLL MFC estão disponíveis como um suplemento livre para Visual Studio de site a partir do MSDN.  Para obter mais informações, consulte [Suplemento a DLL MFC MBCS](../mfc/mfc-mbcs-dll-add-on.md).  
  
 Em um conjunto de caracteres de multibyte, um caractere pode ser um ou dois bytes de largura.  Se for dois bytes de largura, o primeiro byte é um “byte inicial especial” que é escolhido de um intervalo específico, dependendo da página de código está em uso.  Tomada juntos, a ligação e “bytes finais” especificam uma codificação de caracteres exclusivo.  
  
 Se o símbolo `_MBCS` é definido para uma compilação do seu programa, o tipo `TCHAR`, que é baseado `CString` , mapeia a `char`.  Você pode para determinar que bytes em `CString` são bytes inicial e quais são bytes finais.  Funções de fontes da biblioteca em tempo de execução de C para ajudá\-lo a determinar isso.  
  
 Em DBCS, uma cadeia de caracteres determinada pode conter todos os caracteres ANSI de único byte, todos os caracteres de byte duplo, ou uma combinação dos dois.  Essas possibilidades exigem cuidado especial em cadeias de caracteres de análise.  Isso inclui objetos de `CString` .  
  
> [!NOTE]
>  A serialização de cadeia de caracteres Unicode no MFC pode ler Unicode e as cadeias de caracteres de MBCS independentemente de qual versão do aplicativo que você está sendo executado.  Seus arquivos de dados são portáveis entre Unicode e versões de MBCS do seu programa.  
  
 as funções de membro de`CString` “versões especial de texto” genérico que o uso de tempo de execução de C eles funcionam chamam, ou usam funções cientes.  Portanto, por exemplo, se uma função de `CString` normalmente chamaria `strcmp`, chama a função correspondente `_tcscmp` de genérico\- texto em vez disso.  Dependendo de como os símbolos `_MBCS` e `_UNICODE` são definidos, `_tcscmp` mapeia a seguinte maneira:  
  
|||  
|-|-|  
|`_MBCS` definiu|`_mbscmp`|  
|`_UNICODE` definiu|`wcscmp`|  
|Nenhum símbolo definiu|`strcmp`|  
  
> [!NOTE]
>  Os símbolos `_MBCS` e `_UNICODE` são mutuamente exclusivos.  
  
 Os mapeamentos de função de Genérico\- texto para todas as rotinas de cadeia de caracteres\- manipulação de tempo de execução são discutidos em [Referência da biblioteca em tempo de execução do C](../c-runtime-library/c-run-time-library-reference.md).  Em particular, consulte [Internacionalização](../c-runtime-library/internationalization.md).  
  
 Da mesma forma, os métodos de `CString` são implementados usando mapeamentos “genéricos” do tipo de dados.  Para ativar MBCS e Unicode, o MFC usa `TCHAR` para `char`, `LPTSTR` para `char*`, e `LPCTSTR` para `const char*`.  Esses asseguram os mapeamentos corretos para MBCS ou Unicode.  
  
## Consulte também  
 [Cadeias de caracteres](../atl-mfc-shared/strings-atl-mfc.md)   
 [Manipulação da cadeia de caracteres](../c-runtime-library/string-manipulation-crt.md)