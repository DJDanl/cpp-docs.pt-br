---
title: "Requisitos de compila&#231;&#227;o para controles comuns do Windows Vista | Microsoft Docs"
ms.custom: ""
ms.date: "12/10/2016"
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
  - "controles comuns (MFC)"
  - "controles comuns (MFC), requisitos de compilação"
ms.assetid: 025f7d55-55a2-4dcd-8f62-02424e3dcc04
caps.latest.revision: 18
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Requisitos de compila&#231;&#227;o para controles comuns do Windows Vista
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca de \(MFC\) da classe do Microsoft oferece suporte à versão 6,1 dos controles comum do windows.  Os controles comuns são incluídos em [!INCLUDE[windowsver](../Token/windowsver_md.md)] e a biblioteca é incluída em [!INCLUDE[vsipsdk](../mfc/includes/vsipsdk_md.md)].  A biblioteca fornece novos métodos que aprimoram classes existentes, e novas classes e métodos que dão suporte aos controles comuns de[!INCLUDE[windowsver](../Token/windowsver_md.md)].  Quando você cria seu aplicativo, você deve atender os requisitos de compilação e migração que são descritos nas seções a seguir.  
  
## Requisitos de compilação  
  
### Versões com suporte  
 Alguns classes e métodos novos só dão suporte [!INCLUDE[windowsver](../Token/windowsver_md.md)] e posteriores, enquanto outros métodos também oferecem suporte a sistemas operacionais anteriores.  Uma nota na seção de `Requirements` de cada tópico do método especifica quando o sistema operacional mínimo necessário é [!INCLUDE[windowsver](../Token/windowsver_md.md)].  
  
 Se o computador não executa [!INCLUDE[windowsver](../Token/windowsver_md.md)], você pode criar um aplicativo de MFC que é executado em [!INCLUDE[windowsver](../Token/windowsver_md.md)] se você tiver os arquivos de cabeçalho MFC da versão 6,1 em seu computador.  No entanto, os controles comuns que são criados especificamente para [!INCLUDE[windowsver](../Token/windowsver_md.md)] funcionam apenas nesse sistema, e são ignorados por sistemas operacionais anteriores.  
  
### Conjuntos de caracteres com suporte  
 Os controles comum do windows oferecem suporte apenas ao conjunto de caracteres Unicode, e não o conjunto de caracteres ANSI.  Se você criar seu aplicativo na linha de comando, use o seguinte definem \(\/D\) opções do compilador especificar Unicode como o conjunto de caracteres subjacente:  
  
```  
/D_UNICODE /DUNICODE  
```  
  
 Se você criar seu aplicativo no ambiente de desenvolvimento integrado do Visual Studio \(IDE\), especifique a opção de **Conjunto de Caracteres Unicode** da propriedade de **Conjunto de Caracteres** no nó de **Geral** propriedades do projeto.  
  
 A versão de ANSI de vários métodos de MFC foi substituído iniciar com a versão 6,1 dos controles comum do windows.  Para obter mais informações, consulte [APIs ANSI preteridas](../mfc/deprecated-ansi-apis.md).  
  
## Requisitos de migração  
 Se você usar o Visual Studio IDE para criar um novo aplicativo MFC que usa a versão 6,1 dos controles comum do windows, IDE declara automaticamente um manifesto apropriado.  Porém, se você migrar um aplicativo existente MFC de uma versão anterior do Visual Studio e você desejar usar os novos controles comum, IDE não fornece automaticamente as informações manifesta para atualizar seu aplicativo.  Em vez disso, você deve inserir manualmente o código\-fonte seguir em seu arquivo de stdafx.h:  
  
```  
#ifdef UNICODE  
#if defined _M_IX86  
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")  
#elif defined _M_IA64  
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")  
#elif defined _M_X64  
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")  
#else  
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")  
#endif  
#endif  
```  
  
## Consulte também  
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)   
 [Gráfico da hierarquia](../mfc/hierarchy-chart.md)   
 [APIs ANSI preteridas](../mfc/deprecated-ansi-apis.md)