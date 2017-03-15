---
title: "Controles ActiveX MFC: distribuindo controles ActiveX | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "GetWindowsDirectory"
  - "GetSystemDirectory"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "distribuindo controles ActiveX MFC"
  - "Método GetProcAddress, registrando controles ActiveX"
  - "Método GetSystemDirectory"
  - "Método GetWindowsDirectory"
  - "instalando controles ActiveX"
  - "Método LoadLibrary, registrando controles ActiveX"
  - "Controles ActiveX MFC, versões ANSI ou Unicode"
  - "Controles ActiveX MFC, distribuindo"
  - "Controles ActiveX MFC, instalando"
  - "Controles ActiveX MFC, registrando"
  - "MFC40.DLL"
  - "MFC40U.DLL"
  - "MSVCRT40.dll"
  - "OLEPRO32.DLL"
  - "arquivos redistribuíveis, Controles ActiveX MFC"
  - "registrando controles ActiveX"
  - "registrando controles"
  - "registro, registrando controles"
  - "RegSvr32.exe"
ms.assetid: cd70ac9b-f613-4879-9e81-6381fdfda2a1
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: distribuindo controles ActiveX
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve vários problemas relacionados ao reencaminhamento controles ActiveX:  
  
-   [ANSI ou Unicode versões de controle](#_core_ansi_or_unicode_control_versions)  
  
-   [Instalando controles ActiveX e DLL redistribuíveis](#_core_installing_activex_controls_and_redistributable_dlls)  
  
-   [Registrando controles](#_core_registering_controls)  
  
    > [!NOTE]
    >  Para obter informações adicionais sobre como redistribuir controles ActiveX, consulte [Redistribuindo controles](../Topic/Redistributing%20Controls.md).  
  
##  <a name="_core_ansi_or_unicode_control_versions"></a> ANSI ou Unicode versões de controle  
 Você deve decidir se deseja enviar uma versão ANSI ou Unicode de controle, ou ambos.  Esta decisão se baseia nos fatores a portabilidade inerentes em ANSI e em conjuntos de caracteres Unicode.  
  
 Os controles ANSI, que funcionam em todos os sistemas operacionais do Win32, permitem a portabilidade máximo entre vários sistemas operacionais do Win32.  Os controles Unicode só funcionam no Windows NT \(versão 3,51 ou posterior\), mas não no Windows 95 ou Windows 98.  Se a portabilidade é sua preocupação principal, enviar controles ANSI.  Se os controles só serão executadas no Windows NT, você pode enviar controles de Unicode.  Você também pode optar por enviar e ter sua instalação do aplicativo a versão mais apropriado para o sistema operacional do usuário.  
  
##  <a name="_core_installing_activex_controls_and_redistributable_dlls"></a> Instalando controles ActiveX e DLL redistribuíveis  
 O programa de instalação que você fornece com os controles ActiveX deve criar um subdiretório especial de diretório do Windows e instalar os arquivos de .OCX dos controles nele.  
  
> [!NOTE]
>  Use o do windows **GetWindowsDirectory** API em seu programa de instalação do para obter o nome do diretório do Windows.  Talvez você queira derivar o nome do subdiretório do nome da sua empresa ou produto.  
  
 O programa de instalação deve instalar os arquivos necessários redistribuíveis dll no diretório do sistema do windows.  Se algum dos DLL estiverem presentes no computador do usuário, o programa de instalação deverá comparar as versões com as versões que você está instalando.  Reinstale um arquivo apenas se o número de versão é mais alto que o arquivo já instalado.  
  
 Como os controles ActiveX podem ser usados somente em aplicativos de contêiner OLE, não há necessidade de distribuir o conjunto completo de DLL do com os controles.  Você pode assumir que o aplicativo contentor \(ou o sistema operacional próprio\) têm as dlls OLE DB do padrão instalados.  
  
##  <a name="_core_registering_controls"></a> Registrando controles  
 Antes que um controle pode ser usado, as entradas adequadas devem ser criadas para ele na base de dados do registro do windows.  Qualquer contêiner do controle ActiveX fornecem um item de menu para novos usuários aos controles do registro, mas esse recurso pode não estar disponível em todos os contêineres.  Consequentemente, talvez o programa de instalação para registrar os controles quando são instalados.  
  
 Se preferir, você pode gravar seu programa de instalação para registrar diretamente o controle em vez disso.  
  
 Use a API de **LoadLibrary** para carregar a DLL do controle.  Em seguida, use **GetProcAddress** obter o endereço da função de DllRegisterServer “”.  Finalmente, chame a função de `DllRegisterServer` .  O exemplo de código a seguir demonstra um método possível, onde `hLib` armazena o identificador da biblioteca de controle, e repositórios de `lpDllEntryPoint` o endereço da função de DllRegisterServer “”.  
  
 [!code-cpp[NVC_MFC_AxCont#16](../mfc/codesnippet/CPP/mfc-activex-controls-distributing-activex-controls_1.cpp)]  
  
 A vantagem de registrar o controle é diretamente que você não precisa chamar e carregar um processo separado \(ou seja, REGSVR32\), reduzindo o tempo de instalação.  Além disso, porque o registro é um processo interno, o programa de instalação pode manipular erros e situações imprevisíveis melhor do que um processo externo pode.  
  
> [!NOTE]
>  Antes do programa de instalação instala um controle ActiveX, deve chamar **OleInitialize**.  Quando o programa de instalação for concluído, chame **OleUnitialize**.  Isso garante que as dlls do sistema OLE estão no estado apropriado para registrar um controle ActiveX.  
  
 Você deve registrar MFCx0.DLL.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)