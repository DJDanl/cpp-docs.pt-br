---
title: "Programando com o CComBSTR (ATL) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CComBSTR - classe, programando com"
  - "Unicode, usando CComBSTR [ATL]"
ms.assetid: d3bd0851-d132-4be9-9c4c-6ccba17acb2b
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Programando com o CComBSTR (ATL)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe [CComBSTR](../atl/reference/ccombstr-class.md) de ATL fornece um wrapper em torno do tipo de dados de `BSTR` .  Quando `CComBSTR` é uma ferramenta útil, há várias situações que exigem cuidados.  
  
-   [Problemas de conversão](#programmingwithccombstr_conversionissues)  
  
-   [Problemas de escopo](#programmingwithccombstr_scopeissues)  
  
-   [Liberando explicitamente o objeto de CComBSTR](#programmingwithccombstr_explicitlyfreeing)  
  
-   [Usando objetos de CComBSTR em loop](#programmingwithccombstr_usingloops)  
  
-   [Problemas de vazamento de memória](#programmingwithccombstr_memoryleaks)  
  
##  <a name="programmingwithccombstr_conversionissues"></a> Problemas de conversão  
 Embora vários métodos de `CComBSTR` convertam automaticamente um argumento de cadeia de caracteres ANSI em Unicode, os métodos retornará sempre cadeias de caracteres de formato Unicode.  Para converter uma cadeia de caracteres de saída de volta para ANSI, use uma classe de conversão de ATL.  Para obter mais informações sobre as classes de conversão de ATL, consulte [Macros de conversão de cadeia de caracteres de ATL e de MFC](../Topic/ATL%20and%20MFC%20String%20Conversion%20Macros.md).  
  
### Exemplo  
 [!CODE [NVC_ATL_Utilities#114](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#114)]  
  
 Se você estiver usando uma cadeia de caracteres literal para modificar um objeto de `CComBSTR` , use cadeias de caracteres com.  Isso reduzirá conversões desnecessárias.  
  
### Exemplo  
 [!CODE [NVC_ATL_Utilities#115](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#115)]  
  
##  <a name="programmingwithccombstr_scopeissues"></a> Problemas de escopo  
 Como com qualquer uma classe, `CComBSTR` irá liberar os recursos quando sai do escopo.  Se uma função retorna um ponteiro para a cadeia de caracteres de `CComBSTR` , isso pode causar problemas, porque o ponteiro fará referência a memória que já tenha sido liberado.  Em esses casos, use o método de **Copiar** , como mostrado abaixo.  
  
### Exemplo  
 [!CODE [NVC_ATL_Utilities#116](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#116)]  
  
##  <a name="programmingwithccombstr_explicitlyfreeing"></a> Liberando explicitamente o objeto de CComBSTR  
 É possível definir explicitamente a cadeia de caracteres contido no objeto de `CComBSTR` antes de sair do objeto escopo.  Se a cadeia de caracteres é laçada, o objeto de `CComBSTR` é inválido.  
  
### Exemplo  
 [!CODE [NVC_ATL_Utilities#117](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#117)]  
  
##  <a name="programmingwithccombstr_usingloops"></a> Usando objetos de CComBSTR em loop  
 Porque a classe de `CComBSTR` atribui um buffer para executar certas operações, como o operador de `+=` ou o método de **Acrescentar** , não é recomendável que você execute a manipulação de cadeia de caracteres dentro de um loop. forte  Em essas situações, `CStringT` fornece melhor desempenho.  
  
### Exemplo  
 [!CODE [NVC_ATL_Utilities#118](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#118)]  
  
##  <a name="programmingwithccombstr_memoryleaks"></a> Problemas de vazamento de memória  
 Passar o endereço de `CComBSTR` inicializado para uma função como um parâmetro de **\[out\]** causa um vazamento de memória.  
  
 Em o exemplo abaixo, a cadeia de caracteres atribuída para armazenar a cadeia de caracteres `"Initialized"` é vazada quando a função `MyGoodFunction` substitui a cadeia de caracteres.  
  
 [!CODE [NVC_ATL_Utilities#119](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#119)]  
  
 Para evitar o escape, chame o método de **Vazio** em objetos existentes de `CComBSTR` antes de passar o endereço como um parâmetro de **\[out\]** .  
  
 Observe que o mesmo código não poderiam causar um escape se o parâmetro de função foi **\[in, out\]**.  
  
## Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)   
 [Classe de CStringT](../atl-mfc-shared/reference/cstringt-class.md)   
 [wstring](../Topic/wstring.md)   
 [Macros de conversão de cadeia de caracteres](../atl/reference/string-conversion-macros.md)