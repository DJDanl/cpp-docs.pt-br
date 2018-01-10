---
title: 'Controles ActiveX MFC: Distribuindo controles ActiveX | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- GetWindowsDirectory
- GetSystemDirectory
dev_langs: C++
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
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e4ce6602696f733ca3bac03441a58515c57e0dc1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-activex-controls-distributing-activex-controls"></a>Controles ActiveX MFC: distribuindo controles ActiveX
Este artigo descreve vários problemas relacionados à redistribuindo controles ActiveX:  
  
-   [ANSI ou Unicode de controle versões](#_core_ansi_or_unicode_control_versions)  
  
-   [Instalando controles ActiveX e DLLs redistribuíveis](#_core_installing_activex_controls_and_redistributable_dlls)  
  
-   [Registrando controles](#_core_registering_controls)  
  
##  <a name="_core_ansi_or_unicode_control_versions"></a>ANSI ou Unicode de controle versões  
 Você deve decidir se deseja enviar uma versão ANSI ou Unicode de controle, ou ambos. Essa decisão se baseia em fatores de portabilidade inerentes em conjuntos de caracteres ANSI e Unicode.  
  
 Controles de ANSI, que funcionam em todos os sistemas operacionais de Win32, permitem máximo portabilidade entre os vários sistemas operacionais Win32. Controles de Unicode funcionam no somente o Windows NT (versão 3.51 ou posterior), mas não no Windows 95 ou Windows 98. Se portabilidade for sua preocupação principal, controles de ANSI de remessa. Se os controles serão executado somente no Windows NT, você pode enviar os controles de Unicode. Você também pode optar por enviar ambos e que seu aplicativo a instalar a versão mais apropriada para o sistema operacional do usuário.  
  
##  <a name="_core_installing_activex_controls_and_redistributable_dlls"></a>Instalando controles ActiveX e DLLs redistribuíveis  
 O programa de instalação que você forneça aos seus controles ActiveX deve criar um subdiretório especial do diretório do Windows e instale os controles. Arquivos OCX nela.  
  
> [!NOTE]
>  Use o Windows **GetWindowsDirectory** API em seu programa de instalação para obter o nome do diretório do Windows. Talvez você queira derivar o nome do subdiretório do nome da sua empresa ou produto.  
  
 O programa de instalação deve instalar os arquivos DLL redistribuíveis necessários no diretório de sistema do Windows. Se qualquer uma das DLLs que já estão presentes no computador do usuário, o programa de instalação deve comparar suas versões com as versões que você está instalando. Reinstale um arquivo apenas se o seu número de versão é maior do que o arquivo já está instalado.  
  
 Como os controles ActiveX podem ser usados apenas em aplicativos de contêiner OLE, não há necessidade de distribuir o conjunto completo de DLLs OLE com os controles. Você pode presumir que o aplicativo de contenção (ou o próprio sistema operacional) tem o OLE DLLs padrão instalado.  
  
##  <a name="_core_registering_controls"></a>Registrando controles  
 Antes de um controle pode ser usado, entradas apropriadas devem ser criadas para ele no banco de dados de registro do Windows. Alguns contêineres de controle ActiveX fornecem um item de menu para os usuários se registrem novos controles, mas esse recurso pode não estar disponível em todos os contêineres. Portanto, convém o programa de instalação para registrar os controles quando eles são instalados.  
  
 Se preferir, você pode escrever o programa de instalação para registrar o controle diretamente.  
  
 Use o **LoadLibrary** API do Windows para carregar a DLL de controle. Em seguida, use **GetProcAddress** para obter o endereço da função "DllRegisterServer". Finalmente, chame o `DllRegisterServer` função. O exemplo de código a seguir demonstra um método possível, onde `hLib` armazena o identificador da biblioteca de controle, e `lpDllEntryPoint` armazena o endereço da função "DllRegisterServer".  
  
 [!code-cpp[NVC_MFC_AxCont#16](../mfc/codesnippet/cpp/mfc-activex-controls-distributing-activex-controls_1.cpp)]  
  
 Registrando o controle diretamente a vantagem é que você não precisa chamar e carregar um processo separado (ou seja, REGSVR32), reduzindo o tempo de instalação. Além disso, como o registro é um processo interno, o programa de instalação pode tratar erros e situações inesperadas melhores do que um processo externo podem.  
  
> [!NOTE]
>  Antes do programa de instalação instala um controle ActiveX, é necessário chamar **OleInitialize**. Quando o programa de instalação for concluído, chame **OleUnitialize**. Isso garante que as DLLs do sistema OLE estejam no estado apropriado para registrar um controle ActiveX.  
  
 Você deve registrar MFCx0.DLL.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

