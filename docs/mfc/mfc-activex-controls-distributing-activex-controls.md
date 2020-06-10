---
title: 'Controles ActiveX MFC: distribuindo controles ActiveX'
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
ms.openlocfilehash: 11d647922a4f8097e03e112c0c93c833524c2c4e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618211"
---
# <a name="mfc-activex-controls-distributing-activex-controls"></a>Controles ActiveX MFC: distribuindo controles ActiveX

Este artigo aborda vários problemas relacionados à redistribuição de controles ActiveX:

- [Versões de controle ANSI ou Unicode](#_core_ansi_or_unicode_control_versions)

- [Instalando controles ActiveX e DLLs redistribuíveis](#_core_installing_activex_controls_and_redistributable_dlls)

- [Registrando controles](#_core_registering_controls)

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

## <a name="ansi-or-unicode-control-versions"></a><a name="_core_ansi_or_unicode_control_versions"></a>Versões de controle ANSI ou Unicode

Você deve decidir se deseja enviar uma versão ANSI ou Unicode do controle ou ambos. Essa decisão baseia-se nos fatores de portabilidade inerentes aos conjuntos de caracteres ANSI e Unicode.

Controles ANSI, que funcionam em todos os sistemas operacionais Win32, permitem a portabilidade máxima entre os vários sistemas operacionais Win32. Os controles Unicode funcionam apenas no Windows NT (versão 3,51 ou posterior), mas não no Windows 95 ou no Windows 98. Se a portabilidade for sua preocupação principal, envie controles ANSI. Se os controles forem executados somente no Windows NT, você poderá enviar controles Unicode. Você também pode optar por enviar ambos e fazer com que seu aplicativo instale a versão mais apropriada para o sistema operacional do usuário.

## <a name="installing-activex-controls-and-redistributable-dlls"></a><a name="_core_installing_activex_controls_and_redistributable_dlls"></a>Instalando controles ActiveX e DLLs redistribuíveis

O programa de instalação fornecido com os controles ActiveX deve criar um subdiretório especial do diretório do Windows e instalar os controles. Arquivos OCX nele.

> [!NOTE]
> Use a API do Windows `GetWindowsDirectory` em seu programa de instalação para obter o nome do diretório do Windows. Talvez você queira derivar o nome do subdiretório do nome da sua empresa ou produto.

O programa de instalação deve instalar os arquivos DLL redistribuíveis necessários no diretório do sistema do Windows. Se qualquer uma das DLLs já estiver presente na máquina do usuário, o programa de instalação deverá comparar suas versões com as versões que você está instalando. Reinstale um arquivo somente se seu número de versão for maior do que o arquivo já instalado.

Como os controles ActiveX podem ser usados somente em aplicativos de contêiner OLE, não há necessidade de distribuir o conjunto completo de DLLs OLE com seus controles. Você pode assumir que o aplicativo recipiente (ou o próprio sistema operacional) tem as DLLs OLE padrão instaladas.

## <a name="registering-controls"></a><a name="_core_registering_controls"></a>Registrando controles

Antes que um controle possa ser usado, as entradas apropriadas devem ser criadas para ele no banco de dados de registro do Windows. Alguns contêineres de controle ActiveX fornecem um item de menu para os usuários registrarem novos controles, mas esse recurso pode não estar disponível em todos os contêineres. Portanto, talvez você queira que o programa de instalação registre os controles quando eles são instalados.

Se preferir, você pode escrever seu programa de instalação para registrar o controle diretamente em vez disso.

Use a `LoadLibrary` API do Windows para carregar a DLL de controle. Em seguida, use `GetProcAddress` para obter o endereço da função "DllRegisterServer". Por fim, chame a `DllRegisterServer` função. O exemplo de código a seguir demonstra um possível método, onde `hLib` armazena o identificador da biblioteca de controle e `lpDllEntryPoint` armazena o endereço da função "DllRegisterServer".

[!code-cpp[NVC_MFC_AxCont#16](codesnippet/cpp/mfc-activex-controls-distributing-activex-controls_1.cpp)]

A vantagem de registrar o controle diretamente é que você não precisa invocar e carregar um processo separado (ou seja, REGSVR32), reduzindo o tempo de instalação. Além disso, como o registro é um processo interno, o programa de instalação pode lidar com erros e situações imprevistas melhor do que um processo externo pode.

> [!NOTE]
> Antes que o programa de instalação instale um controle ActiveX, ele deve chamar `OleInitialize` . Quando o programa de instalação for concluído, chame `OleUnitialize` . Isso garante que as DLLs do sistema OLE estejam no estado adequado para o registro de um controle ActiveX.

Você deve registrar MFCx0. DLL.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)
