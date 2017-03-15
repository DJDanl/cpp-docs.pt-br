---
title: "Redistribuindo a biblioteca do MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
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
  - "MFC, redistribuindo"
  - "redistribuindo a biblioteca do MFC"
ms.assetid: 72714ce1-385e-4c1c-afa5-96b03e873866
caps.latest.revision: 32
caps.handback.revision: 29
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Redistribuindo a biblioteca do MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você vincular dinamicamente seu aplicativo com a biblioteca MFC, você precisará redistribuir Msvcr100.dll porque todas as DLLs do MFC usam a versão compartilhada da biblioteca em tempo de execução do C \(CRT\).  Você também precisa redistribuir Mfc100u.dll ou Mfc100.dll.  
  
 Se você vincular seu aplicativo estaticamente ao MFC \(ou seja, se você especificar **Usar MFC em uma Static Library** na guia **Geral** na caixa de diálogo **Páginas de Propriedades**\), não será necessário redistribuir Mfc100u.dll ou Mfc100.dll.  No entanto, embora a vinculação estática possa funcionar para os testes e a implantação interna de aplicativos, é recomendável que você não a use para redistribuir o MFC.  Para obter mais informações sobre as estratégias recomendadas para implantar bibliotecas do Visual C\+\+, consulte [Escolhendo uma método de implantação](../ide/choosing-a-deployment-method.md).  
  
 Se seu aplicativo usa as classes MFC que implementam o controle WebBrowser \(por exemplo, [Classe de CHtmlView](../mfc/reference/chtmlview-class.md) ou [Classe de CHtmlEditView](../mfc/reference/chtmleditview-class.md)\), recomendamos que você também instale a versão mais recente do Microsoft Internet Explorer de modo que o computador de destino tenha os arquivos de controle comum mais atuais. \(É necessário, pelo menos, o Internet Explorer 4.0.\) Informações sobre como instalar componentes do Internet Explorer estão disponíveis em "Artigo 185375: Como criar uma única instalação de EXE do Internet Explorer" no site de suporte da Microsoft.  
  
 Se seu aplicativo usa as classes de banco de dados MFC \(por exemplo, [Classe de CRecordset](../Topic/CRecordset%20Class.md) e [Classe de CRecordView](../mfc/reference/crecordview-class.md)\), você deve redistribuir o ODBC e todos os drivers ODBC que seu aplicativo usar.  Para obter mais informações, consulte [Redistribuindo arquivos de suporte de banco de dados](../ide/redistributing-database-support-files.md).  
  
 Se seu aplicativo MFC usar controles de Windows Forms, você deve redistribuir mfcmifc80.dll com seu aplicativo.  Essa DLL é um assembly. NET assinado por nome forte que pode ser redistribuído com um aplicativo na pasta local de seu aplicativo ou implantando\-o no GAC \(Cache de Assembly Global\) usando a [Gacutil.exe \(Ferramenta do Cache de Assemblies Global\)](../Topic/Gacutil.exe%20\(Global%20Assembly%20Cache%20Tool\).md).  
  
 Se você redistribuir uma DLL do MFC, certifique\-se redistribuir a versão comercial e não a versão de depuração.  As versões de depuração de DLL não são redistribuíveis.  Os nomes das versões de depuração das DLLs do MFC terminam com um "d", por exemplo, Mfc100d.dll.  
  
 Se você alterar as fontes do MFC e recompilar a DLL do MFC, será necessário renomear a DLL modificada do MFC de modo que não conflite com a DLL do MFC que está incluída no Visual Studio.  Recomendamos que você não recrie ou renomeie o MFC DLL.  Para obter mais informações, consulte Observação técnica 33 do MFC.  
  
 Você pode redistribuir o MFC usando qualquer VCRedist\_*architecture*.exe, módulos de mesclagem que foram instalados com o Visual Studio, ou implantando a DLL do MFC na mesma pasta do seu aplicativo.  Para obter mais informações sobre como redistribuir o MFC, consulte [Redistribuindo arquivos do Visual C\+\+](../Topic/Redistributing%20Visual%20C++%20Files.md).  
  
## Instalação de componentes localizados MFC  
 Se você decidir localizar seu aplicativo instalando uma DLL de localização MFC, você deverá usar os arquivos redistribuíveis de mesclagem \(.msm\).  Por exemplo, se você desejar localizar seu aplicativo em um computador x86, será necessário mesclar Microsoft\_VC100\_MFCLOC\_x86.msm no pacote de instalação para um computador x86.  
  
 Os arquivos .msm redistribuíveis contêm as DLLs que são usadas para localização.  Há uma DLL para cada linguagem com suporte.  O processo de instalação instala essas DLLs na pasta %windir%\\system32\\ do computador de destino.  
  
 Para obter mais informações sobre como localizar aplicativos MFC, consulte [TN057: localização de componentes MFC](../mfc/tn057-localization-of-mfc-components.md), e também [Artigo 208983: Como usar DLLs MFC LOC](http://go.microsoft.com/fwlink/?LinkId=198025) no site de suporte da Microsoft.  
  
 Você pode redistribuir DLLs de localização do MFC implantando a DLL do MFC na sua pasta local do aplicativo.  Para obter mais informações sobre como redistribuir bibliotecas do Visual C\+\+, consulte [Redistribuindo arquivos do Visual C\+\+](../Topic/Redistributing%20Visual%20C++%20Files.md).  
  
## Consulte também  
 [Redistribuindo arquivos do Visual C\+\+](../Topic/Redistributing%20Visual%20C++%20Files.md)