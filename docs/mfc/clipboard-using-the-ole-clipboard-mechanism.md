---
title: "&#193;rea de Transfer&#234;ncia: usando o mecanismo &#193;rea de Transfer&#234;ncia OLE | Microsoft Docs"
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
  - "aplicativos [OLE], Área de Transferência"
  - "Área de Transferência [C++], Formatos OLE"
  - "formatos [C++], Área de Transferência para OLE"
  - "Área de Transferência OLE"
  - "Área de Transferência OLE, formatos"
ms.assetid: 229cc610-5bb1-435e-bd20-2c8b9964d1af
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# &#193;rea de Transfer&#234;ncia: usando o mecanismo &#193;rea de Transfer&#234;ncia OLE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Formatos padrão de OLE e alguns formatos OLE\- específicos para transferir dados através da área de transferência.  
  
 Quando você recortam ou os dados de cópia de um aplicativo, os dados são armazenados na área de transferência a ser usada posteriormente em operações de pasta.  Esses dados estão em vários formatos.  Quando um usuário escolhe para colar dados da área de transferência, o aplicativo pode escolher quais esses formatos a usar.  O aplicativo deve ser gravado para escolher o formato que fornece a maioria das informações, a menos que o usuário solicitar especificamente um determinado formato, usando o especiais da pasta.  Antes de continuar, talvez você queira ler os tópicos de [Objetos de dados e fontes de dados \(OLE\)](../mfc/data-objects-and-data-sources-ole.md) .  Descreve os fundamentos de como as transferências de dados funciona, e de como os implementar em seus aplicativos.  
  
 O windows definem vários formatos padrão que podem ser usados transferindo dados através da área de transferência.  Esses incluem metarquivos, texto, bitmaps, e outros.  OLE define um número de OLE\- formatos específicos, também.  Para aplicativos que precisam mais detalhes do que determinado por esses formatos padrão, é uma boa ideia registre seus próprios formatos personalizados da área de transferência.  Use a função [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) da API do Win32 para fazer isso.  
  
 Por exemplo, Microsoft Excel registra um formato personalizado para planilhas.  Esse formato leva muito mais informações do que, por exemplo, um bitmap faz.  Quando esses dados forem colados em um aplicativo que dê suporte ao formato da planilha, todas as fórmulas e valores da planilha são mantidos e podem ser atualizados se necessário.  O Microsoft Excel também coloca dados na área de transferência em formatos de modo que possa ser colada como um item OLE.  Qualquer contêiner OLE do documento pode colar essas informações como um item inserido.  Este item inserido pode ser alterado usando o Microsoft Excel.  A área de transferência também contém um bitmap simples da imagem do intervalo selecionado na planilha.  Isso também pode ser colados em contêineres com OLE DB do documento ou em editores de bitmap, como paint.  No caso de um bitmap, porém, não há como manipular os dados como uma planilha.  
  
 Para recuperar a quantidade de informações máximo da área de transferência, os aplicativos devem verificar esses formatos personalizados antes de colar dados da área de transferência.  
  
 Por exemplo, para habilitar o comando de divisão, você pode gravar em um manipulador algo como:  
  
 [!CODE [NVC_MFCListView#3](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCListView#3)]  
  
## Que você deseja saber mais?  
  
-   [Copiando e colando dados](../Topic/Clipboard:%20Copying%20and%20Pasting%20Data.md)  
  
-   [Adicionar outros formatos](../mfc/clipboard-adding-other-formats.md)  
  
-   [Usando a área de transferência do windows](../mfc/clipboard-using-the-windows-clipboard.md)  
  
-   [OLE](../mfc/ole-background.md)  
  
-   [Objetos de dados OLE e fontes de dados e transferência de dados\)](../mfc/data-objects-and-data-sources-ole.md)  
  
## Consulte também  
 [Área de Transferência](../mfc/clipboard.md)