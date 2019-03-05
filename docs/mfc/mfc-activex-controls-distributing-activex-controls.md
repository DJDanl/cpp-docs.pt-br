---
title: 'Controles ActiveX MFC: Distribuindo controles ActiveX'
ms.date: 09/12/2018
f1_keywords:
- GetWindowsDirectory
- GetSystemDirectory
helpviewer_keywords:
- MFC ActiveX controls [MFC], ANSI or Unicode versions
- RegSvr32.exe
- MFC ActiveX controls [MFC], distributing
- distributing MFC ActiveX controls
- redistributable files, MFC ActiveX controls
- GetSystemDirectory method [MFC]
- registering ActiveX controls
- MSVCRT40.dll
- registry [MFC], registering controls
- LoadLibrary method, registering ActiveX controls
- MFC40U.DLL
- MFC40.DLL
- GetWindowsDirectory method [MFC]
- installing ActiveX controls
- GetProcAddress method, registering ActiveX controls
- MFC ActiveX controls [MFC], installing
- MFC ActiveX controls [MFC], registering
- registering controls
- OLEPRO32.DLL
ms.assetid: cd70ac9b-f613-4879-9e81-6381fdfda2a1
ms.openlocfilehash: 409ace2197396cf7adbd330cfbd891745a23cf53
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57300109"
---
# <a name="mfc-activex-controls-distributing-activex-controls"></a>Controles ActiveX MFC: Distribuindo controles ActiveX

Este artigo aborda vários problemas relacionados à redistribuindo controles ActiveX:

- [Versões de controle Unicode ou ANSI](#_core_ansi_or_unicode_control_versions)

- [Instalar controles ActiveX e DLLs redistribuíveis](#_core_installing_activex_controls_and_redistributable_dlls)

- [Registrando controles](#_core_registering_controls)

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

##  <a name="_core_ansi_or_unicode_control_versions"></a> Versões de controle Unicode ou ANSI

Você deve decidir se deseja enviar uma versão ANSI ou Unicode de controle, ou ambos. Essa decisão se baseia em fatores de portabilidade inerentes em conjuntos de caracteres ANSI e Unicode.

Controles de ANSI, que funcionam em todos os sistemas operacionais Win32, permitem máximo de portabilidade entre os vários sistemas operacionais Win32. Controles de Unicode funcionam no apenas Windows NT (versão 3.51 ou posterior), mas não no Windows 95 ou Windows 98. Se a portabilidade for sua preocupação principal, controles de ANSI de remessa. Se os controles serão executados somente no Windows NT, você pode enviar os controles de Unicode. Você também pode optar por enviar ambos e que seu aplicativo a instalar a versão mais apropriada para o sistema operacional do usuário.

##  <a name="_core_installing_activex_controls_and_redistributable_dlls"></a> Instalar controles ActiveX e DLLs redistribuíveis

O programa de instalação que você fornecer a seus controles ActiveX deve criar um subdiretório especial do diretório do Windows e instale dos controles. Arquivos OCX nela.

> [!NOTE]
>  Usar o Windows `GetWindowsDirectory` API em seu programa de instalação para obter o nome do diretório do Windows. Talvez você queira derivar o nome do subdiretório do nome da sua empresa ou produto.

O programa de instalação deve instalar os arquivos DLL redistribuíveis necessários no diretório do sistema Windows. Se qualquer uma das DLLs ainda estão presentes no computador do usuário, o programa de instalação deve comparar suas versões com as versões que você está instalando. Reinstale um arquivo apenas se o seu número de versão é maior do que o arquivo já está instalado.

Como os controles ActiveX podem ser usados somente em aplicativos de contêiner OLE, não é necessário para distribuir o conjunto completo de DLLs OLE com seus controles. Você pode presumir que o aplicativo de contenção (ou o próprio sistema operacional) tem a OLE DLLs padrão instalado.

##  <a name="_core_registering_controls"></a> Registrando controles

Antes de um controle pode ser usado, as entradas apropriadas devem ser criadas para ele no banco de dados de registro do Windows. Alguns contêineres de controle ActiveX fornecem um item de menu para que os usuários registrem os novos controles, mas esse recurso pode não estar disponível em todos os contêineres. Portanto, convém seu programa de instalação para registrar os controles quando eles são instalados.

Se você preferir, você pode escrever o seu programa de instalação para registrar o controle diretamente.

Use o `LoadLibrary` Windows API para carregar a DLL de controle. Em seguida, use `GetProcAddress` para obter o endereço da função "DllRegisterServer". Por fim, chame o `DllRegisterServer` função. O exemplo de código a seguir demonstra um método possível, onde `hLib` armazena o identificador da biblioteca de controle, e `lpDllEntryPoint` armazena o endereço da função "DllRegisterServer".

[!code-cpp[NVC_MFC_AxCont#16](../mfc/codesnippet/cpp/mfc-activex-controls-distributing-activex-controls_1.cpp)]

A vantagem de registrar o controle diretamente é que você não precisa invocar e carregar um processo separado (ou seja, REGSVR32), reduzindo o tempo de instalação. Além disso, como o registro é um processo interno, o programa de instalação pode tratar erros e situações imprevistas melhores do que um processo externo podem.

> [!NOTE]
>  Antes que seu programa de instalação instala um controle ActiveX, ele deverá chamar `OleInitialize`. Quando o programa de instalação for concluído, chame `OleUnitialize`. Isso garante que as DLLs do sistema OLE estão no estado apropriado para o registro de um controle ActiveX.

Você deve registrar MFCx0.DLL.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
