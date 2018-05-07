---
title: Redistribuindo a biblioteca do MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC, redistributing
- redistributing MFC library
ms.assetid: 72714ce1-385e-4c1c-afa5-96b03e873866
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 19a49bf18721f605abe0c6e496d3532012c9c92c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="redistributing-the-mfc-library"></a>Redistribuindo a biblioteca do MFC
Se você vincular dinamicamente seu aplicativo para a biblioteca do MFC, você deve redistribuir a DLL do MFC correspondente. Por exemplo, se seu aplicativo MFC criado usando a versão do MFC que é fornecido com o Visual Studio 2015, você deve redistribuir mfc140.dll ou mfc140u.dll, dependendo de seu aplicativo é compilado para suporte de Unicode ou caracteres estreitas.  
  
> [!NOTE]
>  Os arquivos mfc140.dll foram omitidos da pasta arquivos redistribuíveis no Visual Studio 2015 RTM. Você pode usar as versões instaladas pelo Visual Studio 2015 nos diretórios Windows\system32 e Windows\syswow64 em vez disso.  
  
 Como todas as DLLs MFC usam a versão compartilhada da biblioteca de tempo de execução do C (CRT), também precisará redistribuir CRT. A versão do MFC que é fornecido com o Visual Studio 2015 usa a biblioteca CRT universal, que é distribuída como parte do Windows 10. Para executar um aplicativo MFC criado usando o Visual Studio 2015 em versões anteriores do Windows, você deve redistribuir o Universal CRT. Para obter informações sobre como redistribuir o universal CRT como um componente do sistema operacional ou usando a implantação local, consulte [apresentando o Universal CRT](http://go.microsoft.com/fwlink/p/?linkid=617977). Para baixar o Universal CRT para implantação central em versões do Windows, consulte [Windows 10 Universal C Runtime](http://go.microsoft.com/fwlink/p/?LinkId=619489). Versões de específicos de arquitetura redistribuíveis de ucrtbase.dll para implantação local são encontradas no SDK do Windows. Por padrão, o Visual Studio instala-os em C:\Program Files (x86) \Windows Kits\10\Redist\ucrt\DLLs\ em um subdiretório de arquitetura específicas.  
  
 Se seu aplicativo criado usando uma versão anterior da biblioteca MFC, você deve redistribuir a DLL do CRT correspondente do diretório de arquivos redistribuíveis. Por exemplo, se seu aplicativo MFC é criado usando o conjunto de ferramentas do Visual Studio 2013 (vc120), você deve redistribuir o msvcr120.dll. Você também precisará redistribuir o mfc correspondente`<version>`mfc ou u.dll`<version>`. dll.  
  
 Se você vincular estaticamente seu aplicativo MFC (ou seja, se você especificar **Use MFC em uma biblioteca estática** no **geral** guia o **páginas de propriedade** caixa de diálogo), você não tem para redistribuir uma DLL MFC. No entanto, embora a vinculação estática pode funcionar para teste e implantação interna de aplicativos, é recomendável que você não usá-lo para redistribuir o MFC. Para obter mais informações sobre as estratégias recomendadas para a implantação de bibliotecas do Visual C++, consulte [escolhendo um método de implantação](../ide/choosing-a-deployment-method.md).  
  
 Se seu aplicativo usa as classes MFC que implementam o controle WebBrowser (por exemplo, [CHtmlView classe](../mfc/reference/chtmlview-class.md) ou [CHtmlEditView classe](../mfc/reference/chtmleditview-class.md)), é recomendável que você também pode instalar a versão mais recente do O Microsoft Internet Explorer para que o computador de destino tenha os arquivos de controle comum mais atuais. (No mínimo, Internet Explorer 4.0 é necessário.) Informações sobre como instalar componentes do Internet Explorer estão disponíveis em "Artigo 185375: como para criar um único EXE instalar do Internet Explorer" no site da Microsoft Support.  
  
 Se seu aplicativo usa as classes de banco de dados MFC (por exemplo, [CRecordset classe](../mfc/reference/crecordset-class.md) e [classe CRecordView](../mfc/reference/crecordview-class.md)), você deve redistribuir o ODBC e drivers ODBC que seu aplicativo usa. Para obter mais informações, consulte [redistribuindo arquivos de suporte do banco de dados](../ide/redistributing-database-support-files.md).  
  
 Se o aplicativo do MFC usar controles de formulários do Windows, você deve redistribuir mfcmifc80 com seu aplicativo. Essa DLL é um assembly .NET com nome forte assinado que pode ser redistribuído com um aplicativo em sua pasta local do aplicativo ou por implantá-lo para o Cache de Assembly Global (GAC) usando o [Gacutil.exe (ferramenta de Cache de Assembly Global)](/dotnet/framework/tools/gacutil-exe-gac-tool).  
  
 Se você redistribuir uma DLL MFC, certifique-se redistribuir a versão comercial e não a versão de depuração. As versões de depuração das DLLs não são redistribuíveis. Os nomes das versões de depuração das DLLs MFC terminam com um "d", por exemplo, Mfc140d.dll.  
  
 Você pode redistribuir MFC usando o VCRedist _*arquitetura*.exe, módulos de mesclagem que são instalados com o Visual Studio ou ao implantar a DLL do MFC para a mesma pasta que o aplicativo. Para obter mais informações sobre como redistribuir MFC, consulte [arquivos de redistribuição do Visual C++](../ide/redistributing-visual-cpp-files.md).  
  
## <a name="installation-of-localized-mfc-components"></a>Instalação de componentes MFC localizados  
 Se você decidir localizar o aplicativo instalando uma DLL de localização do MFC, você deve usar os arquivos redistribuíveis de mesclagem (. msm). Por exemplo, se você deseja localizar seu aplicativo em um x86 computador, você deve mesclar Microsoft_VC`<version>`_MFCLOC_x86.msm para o pacote de instalação para x86 de um computador.  
  
 Os arquivos. msm redistribuível contêm as DLLs que são usadas para localização. Há uma DLL para cada idioma com suporte. O processo de instalação instala essas DLLs na pasta %windir%\system32\ no computador de destino.  
  
 Para obter mais informações sobre como localizar aplicativos MFC, consulte [TN057: localização de componentes MFC](../mfc/tn057-localization-of-mfc-components.md)e também [208983 artigo: como usar DLLs do MFC LOC](http://go.microsoft.com/fwlink/p/?linkid=198025) no site da Microsoft Support.  
  
 Você pode redistribuir localização MFC DLLs implantando a DLL do MFC em sua pasta local do aplicativo. Para obter mais informações sobre como redistribuir as bibliotecas do Visual C++, consulte [arquivos de redistribuição do Visual C++](../ide/redistributing-visual-cpp-files.md).  
  
## <a name="see-also"></a>Consulte também  
 [Redistribuindo arquivos do Visual C++](../ide/redistributing-visual-cpp-files.md)