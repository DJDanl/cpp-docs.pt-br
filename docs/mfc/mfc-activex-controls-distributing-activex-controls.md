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
ms.openlocfilehash: 1ada1c801b2d9d62f1cc4cd5bf72a2995225b3de
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364620"
---
# <a name="mfc-activex-controls-distributing-activex-controls"></a>Controles ActiveX MFC: distribuindo controles ActiveX

Este artigo discute várias questões relacionadas à redistribuição de controles ActiveX:

- [Versões de controle ANSI ou Unicode](#_core_ansi_or_unicode_control_versions)

- [Instalando controles ActiveX e DLLs reditribuíveis](#_core_installing_activex_controls_and_redistributable_dlls)

- [Registro de Controles](#_core_registering_controls)

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

## <a name="ansi-or-unicode-control-versions"></a><a name="_core_ansi_or_unicode_control_versions"></a>Versões de controle ANSI ou Unicode

Você deve decidir se deve enviar uma versão ANSI ou Unicode do controle, ou ambos. Essa decisão baseia-se em fatores de portabilidade inerentes aos conjuntos de caracteres ANSI e Unicode.

Os controles ANSI, que funcionam em todos os sistemas operacionais Win32, permitem a máxima portabilidade entre os vários sistemas operacionais Win32. Os controles Unicode funcionam apenas no Windows NT (versão 3.51 ou posterior), mas não no Windows 95 ou no Windows 98. Se a portabilidade é sua principal preocupação, desemifique controles ANSI. Se seus controles forem executados apenas no Windows NT, você poderá enviar controles Unicode. Você também pode optar por enviar ambos e fazer com que seu aplicativo instale a versão mais adequada para o sistema operacional do usuário.

## <a name="installing-activex-controls-and-redistributable-dlls"></a><a name="_core_installing_activex_controls_and_redistributable_dlls"></a>Instalando controles ActiveX e DLLs reditribuíveis

O programa de configuração fornecido pelos controles ActiveX deve criar um subdiretório especial do diretório do Windows e instalar os controles. Arquivos OCX nele.

> [!NOTE]
> Use a `GetWindowsDirectory` API do Windows em seu programa de configuração para obter o nome do diretório do Windows. Você pode querer derivar o nome do subdiretório do nome da sua empresa ou produto.

O programa de configuração deve instalar os arquivos DLL reavermelhados necessários no diretório do sistema Windows. Se algum dos DLLs já estiver presente na máquina do usuário, o programa de configuração deve comparar suas versões com as versões que você está instalando. Reinstale um arquivo somente se o número da sua versão for maior do que o arquivo já instalado.

Como os controles ActiveX podem ser usados apenas em aplicações de contêineres OLE, não há necessidade de distribuir o conjunto completo de DLLs OLE com seus controles. Você pode assumir que o aplicativo de contenção (ou o próprio sistema operacional) tem as DLLs OLE padrão instaladas.

## <a name="registering-controls"></a><a name="_core_registering_controls"></a>Registro de Controles

Antes que um controle possa ser usado, as entradas apropriadas devem ser criadas para ele no banco de dados de registro do Windows. Alguns contêineres de controle ActiveX fornecem um item de menu para os usuários registrarem novos controles, mas esse recurso pode não estar disponível em todos os recipientes. Portanto, você pode querer que seu programa de configuração registre os controles quando eles estiverem instalados.

Se preferir, você pode escrever seu programa de configuração para registrar o controle diretamente.

Use `LoadLibrary` a API do Windows para carregar o DLL de controle. Em seguida, use `GetProcAddress` para obter o endereço da função "DllRegisterServer". Finalmente, chame `DllRegisterServer` a função. A amostra de código a `hLib` seguir demonstra um método possível, onde armazena a alça da biblioteca de controle e `lpDllEntryPoint` armazena o endereço da função "DllRegisterServer".

[!code-cpp[NVC_MFC_AxCont#16](../mfc/codesnippet/cpp/mfc-activex-controls-distributing-activex-controls_1.cpp)]

A vantagem de registrar o controle diretamente é que você não precisa invocar e carregar um processo separado (ou seja, REGSVR32), reduzindo o tempo de instalação. Além disso, como o registro é um processo interno, o programa de configuração pode lidar com erros e situações imprevistas melhor do que um processo externo pode.

> [!NOTE]
> Antes que seu programa de configuração instale `OleInitialize`um controle ActiveX, ele deve chamar . Quando seu programa de configuração estiver concluído, ligue . `OleUnitialize` Isso garante que os DLLs do sistema OLE estejam no estado adequado para registrar um controle ActiveX.

Você deve registrar MFCx0.DLL.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
