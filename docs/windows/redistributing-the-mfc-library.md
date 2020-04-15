---
title: Redistribuindo a biblioteca do MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, redistributing
- redistributing MFC library
ms.assetid: 72714ce1-385e-4c1c-afa5-96b03e873866
ms.openlocfilehash: e1434bee6d134d4c02b2c06125d340a68a6c305d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359899"
---
# <a name="redistributing-the-mfc-library"></a>Redistribuindo a biblioteca do MFC

Se você vincular o aplicativo dinamicamente à biblioteca MFC, precisará redistribuir a DLL do MFC correspondente. Por exemplo, se o aplicativo MFC for compilado usando a versão do MFC fornecida com o Visual Studio 2015, você precisará redistribuir mfc140.dll ou mfc140u.dll, dependendo se o aplicativo é compilado para suporte para Unicode ou para caracteres estreitos.

> [!NOTE]
> Os arquivos mfc140.dll foram omitidos do diretório de arquivos redistribuíveis no Visual Studio 2015 RTM. Em vez disso, use as versões instaladas pelo Visual Studio 2015 nos diretórios Windows\system32 e Windows\syswow64.

Como todas as DLLs do MFC usam a versão compartilhada do CRT (biblioteca de runtime do C), você também precisará redistribuir o CRT. A versão do MFC fornecida com o Visual Studio 2015 usa a biblioteca CRT universal, que é distribuída como parte do Windows 10. Para executar um aplicativo MFC compilado usando o Visual Studio 2015 em versões anteriores do Windows, você precisará redistribuir o CRT Universal. Para obter informações sobre como redistribuir o CRT universal como um componente do sistema operacional ou usando a implantação local, confira [Apresentação do CRT Universal](https://devblogs.microsoft.com/cppblog/introducing-the-universal-crt/). Para baixar o CRT universal para implantação central em versões suportadas do Windows, consulte [Windows 10 Universal C Runtime](https://www.microsoft.com/download/details.aspx?id=48234). Encontre versões de ucrtbase.dll específicas a uma arquitetura redistribuível para implantação local no SDK do Windows. Por padrão, o Visual Studio instala-as em C:\Arquivos de Programas (x86)\Windows Kits\10\Redist\ucrt\DLLs\ em um subdiretório específico a uma arquitetura.

Se o aplicativo for compilado usando uma versão anterior da biblioteca MFC, você precisará redistribuir a DLL do CRT correspondente por meio do diretório de arquivos redistribuíveis. Por exemplo, se o aplicativo MFC for compilado usando o conjunto de ferramentas do Visual Studio 2013 (vc120), você precisará redistribuir o msvcr120.dll. Você também precisará redistribuir a mfc`<version>`u.dll ou mfc`<version>`.dll correspondente.

Se você vincular estaticamente o aplicativo ao MFC (ou seja, se você especificar **Usar o MFC em uma Biblioteca Estática** na guia **Geral** da caixa de diálogo **Páginas de Propriedades**), não precisará redistribuir uma DLL do MFC. No entanto, embora a vinculação estática possa funcionar para teste e implantação interna de aplicativos, recomendamos que você não a use para redistribuir o MFC. Para obter mais informações sobre as estratégias recomendadas para a implantação de bibliotecas do Visual C++, confira [Escolhendo um método de implantação](choosing-a-deployment-method.md).

Se o aplicativo usar as classes MFC que implementam o controle WebBrowser (por exemplo, [Classe CHtmlView](../mfc/reference/chtmlview-class.md) ou [Classe CHtmlEditView](../mfc/reference/chtmleditview-class.md)), recomendamos que você também instale a versão atual do Microsoft Internet Explorer, de modo que o computador de destino tenha os arquivos de controle comum mais atuais. (No mínimo, é necessário o Internet Explorer 4.) Informações sobre como instalar componentes do Internet Explorer estão disponíveis no "Artigo 185375: Como Criar uma Única Instalação EXE do Internet Explorer" no site de suporte da Microsoft.

Se o aplicativo usar as classes de banco de dados MFC (por exemplo, [Classe CRecordset](../mfc/reference/crecordset-class.md) e [Classe CRecordView](../mfc/reference/crecordview-class.md)), você precisará redistribuir o ODBC e os drivers ODBC usados pelo aplicativo.

Se o aplicativo MFC usar controles do Windows Forms, você precisará redistribuir mfcmifc80.dll com o aplicativo. Essa DLL é um assembly .NET assinado com nome forte que pode ser redistribuído com um aplicativo em sua pasta local do aplicativo ou implantando-o no GAC (Cache de Assembly Global) usando o [Gacutil.exe (Ferramenta do Cache de Assembly Global)](/dotnet/framework/tools/gacutil-exe-gac-tool).

Se você redistribuir uma DLL do MFC, lembre-se de redistribuir a versão comercial e não a versão de depuração. As versões de depuração das DLLs não são redistribuíveis. Os nomes das versões de depuração das DLLs do MFC terminam com um "d", por exemplo, Mfc140d.dll.

Redistribua o MFC usando o VCRedist_*arquitetura*.exe, os módulos de mesclagem que são instalados com o Visual Studio ou implantando a DLL do MFC na mesma pasta do aplicativo. Para obter mais informações sobre como redistribuir o MFC, confira [Redistribuindo arquivos do Visual C++](redistributing-visual-cpp-files.md).

## <a name="installation-of-localized-mfc-components"></a>Instalação de componentes localizados do MFC

Se optar por localizar seu aplicativo instalando uma DLL de localização do MFC, use os arquivos de mesclagem redistribuíveis (.msm). Por exemplo, caso deseje localizar seu aplicativo em um computador x86, mescle Microsoft_VC`<version>`_MFCLOC_x86.msm no pacote de instalação de um computador x86.

Os arquivos .msm redistribuíveis contêm as DLLs usadas para localização. Há uma DLL para cada idioma compatível. O processo de instalação instala essas DLLs na pasta %windir%\system32\ no computador de destino.

Para obter mais informações sobre como localizar aplicativos de MFC, consulte [TN057: localização de componentes MFC](../mfc/tn057-localization-of-mfc-components.md).

Redistribua DLLs de localização do MFC implantando a DLL do MFC na pasta local do aplicativo. Para obter mais informações sobre como redistribuir bibliotecas do Visual C++, confira [Redistribuindo arquivos do Visual C++](redistributing-visual-cpp-files.md).

## <a name="see-also"></a>Confira também

[Redistribuindo arquivos do Visual C++](redistributing-visual-cpp-files.md)
