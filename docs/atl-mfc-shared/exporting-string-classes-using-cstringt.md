---
title: "Exportando classes de cadeia de caracteres usando CStringT | Microsoft Docs"
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
  - "Classe de CStringT, exportando cadeias de caracteres"
ms.assetid: bdfc441e-8d2a-461c-9885-46178066c09f
caps.latest.revision: 15
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exportando classes de cadeia de caracteres usando CStringT
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em o passado, os desenvolvedores MFC derivada de `CString` para especializar suas próprias classes de cadeia de caracteres.  Em o Microsoft Visual C\+\+ .NET \(MFC 8,0\), a classe de [CString](../atl-mfc-shared/using-cstring.md) foi substituída por uma classe de modelo chamada [CStringT](../atl-mfc-shared/reference/cstringt-class.md).  Isso forneceu vários benefícios:  
  
-   Permitiu que a classe MFC `CString` é usada em projetos de ATL sem vincular na biblioteca estático ou maior no DLL MFC.  
  
-   Com a nova classe de modelo de `CStringT` , você pode personalizar o comportamento de `CString` usando os parâmetros de modelo que especificam traços de caractere, semelhantes aos modelos na biblioteca padrão \(STL\) do modelo.  
  
-   Quando você exportar sua própria classe de cadeia de caracteres de uma DLL usando `CStringT`, o compilador também exportar automaticamente a classe base de `CString` .  Desde que `CString` é também uma classe de modelo, pode ser instanciada pelo compilador quando usado, a menos que o compilador esteja ciente que `CString` é importado de uma DLL.  Se você migrou projetos do Visual C\+\+ 6,0 para Visual C\+\+ .NET, você pode ter consultado erros de símbolo de vinculador para `CString` multiplicar\- definido por causa de colisão de `CString` importado de uma DLL e versão localmente instanciada.  A maneira apropriada de fazer isso é descrita abaixo.  Para obter mais informações sobre esse problema, consulte o artigo de Base de Dados de Conhecimento, “vinculando erros quando você importar classes derivadas CString\-” \(Q309801\) na Biblioteca MSDN um CD\-ROM [http:\/\/support.microsoft.com\/default.aspx](http://support.microsoft.com/default.aspx)ou.  
  
 O cenário a seguir causará o vinculador a erros de símbolo de produto para classes definidas em.  Suponha que você está exportando `CString`\- classe derivada \(`CMyString`\) de uma DLL de extensão MFC:  
  
 [!CODE [NVC_MFC_DLL#6](../CodeSnippet/VS_Snippets_Cpp/NVC_MFC_DLL#6)]  
  
 O código consumidor usa uma mistura de `CString` e de `CMyString`. “  MyString.h” não é incluído no cabeçalho pré\-compilado, e qualquer uso de `CString` não tem `CMyString` visível.  
  
 Suponha que você use as classes de `CString` e de `CMyString` nos arquivos de origem separado, Source1.cpp e Source2.cpp.  Em Source1.cpp, você usa `CMyString` e o \#include MyString.h.  Em Source2.cpp, você usa `CString`, mas não faz o \#include MyString.h.  Em esse caso, o vinculador queixar\-se\-á sobre `CStringT` que é definido em.  Isso é causado por `CString` que está sendo importado de DLL que `CMyString`, exportar e instanciado localmente pelo compilador através do modelo de `CStringT` .  
  
 Para resolver esse problema, faça o seguinte:  
  
 Exportar `CStringA` e `CStringW` \(e as classes base de MFC90.DLL necessárias\).  Projetos que incluem o MFC sempre usará o MFC `CStringA` exportado DLL e `CStringW`, como em implementações anteriores MFC.  
  
 Crie uma classe derivada exportável usando o modelo de `CStringT` , como `CStringT_Exported` abaixo, por exemplo:  
  
 [!CODE [NVC_MFC_DLL#7](../CodeSnippet/VS_Snippets_Cpp/NVC_MFC_DLL#7)]  
  
 Em AfxStr.h, substitua `CString`anterior, `CStringA`, e typedefs de `CStringW` como segue:  
  
 [!CODE [NVC_MFC_DLL#8](../CodeSnippet/VS_Snippets_Cpp/NVC_MFC_DLL#8)]  
  
 Há várias restrições:  
  
-   Você não deve exportar `CStringT` próprio porque isso causará projetos de ATL\-only exportar uma classe específica de `CStringT` .  
  
-   Usando uma classe derivada exportável de `CStringT` minimiza que possuem funcionalidade de `CStringT` de que implementam.  O código adicional é limitado a encaminhar construtores para a classe base de `CStringT` .  
  
-   `CString`, `CStringA`, e `CStringW` só devem ser marcado `__declspec(dllexport/dllimport)` quando você está criando com uma DLL MFC compartilhado.  Se vinculando com uma biblioteca estática MFC, você não deve marcar como exportadas; essas classes caso contrário, o uso interno de `CString`, de `CStringA`, e de `CStringW` dentro de DLL do usuário irá marcar `CString` como exportado também.  
  
## Tópicos relacionados  
 [Classe de CStringT](../atl-mfc-shared/reference/cstringt-class.md)  
  
## Consulte também  
 [Usando CStringT](../atl-mfc-shared/using-cstringt.md)   
 [Usando CString](../atl-mfc-shared/using-cstring.md)