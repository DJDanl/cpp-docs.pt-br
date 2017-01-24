---
title: "Estrat&#233;gias de internacionaliza&#231;&#227;o | Microsoft Docs"
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
  - "conjunto de caracteres [C++], estratégias de programação internacional"
  - "globalização [C++], conjuntos de caracteres"
  - "código portátil de idioma [C++]"
  - "localização [C++], conjuntos de caracteres"
  - "MBCS [C++], estratégias de internacionalização"
  - "Unicode [C++], globalizando aplicativos"
  - "Win32 [C++], estratégias de programação internacional"
  - "API do Windows [C++], estratégias de programação internacional"
ms.assetid: b09d9854-0709-4b9a-a00c-b0b8bc4199b1
caps.latest.revision: 8
caps.handback.revision: 8
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Estrat&#233;gias de internacionaliza&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Dependendo dos seus sistemas operacionais e mercados de destino, você tem várias estratégias de internacionalização:  
  
-   Seu aplicativo usa o Unicode e executá\-lo como consequência no Windows 2000 e Windows NT, mas não no Windows 95 ou Windows 98.  
  
     Você usa a funcionalidade específica unicode e todos os caracteres são de 16 bits largura \(embora você possa usar caracteres ANSI em algumas partes de seu programa para objetivos especiais\).  A biblioteca de tempo de execução C fornece macros funções, e tipos de dados para programação somente Unicode.  O MFC for compatível com unicode completamente.  
  
-   O aplicativo usa e MBCS pode ser executado em qualquer plataforma do Win32.  
  
     Você usar a funcionalidade MBCS\- específica.  As cadeias de caracteres podem conter caracteres, caracteres de dois bytes, ou ambas de um byte.  A biblioteca de tempo de execução C fornece macros funções, e tipos de dados para a programação de MBCS somente.  MFC O MBCS\- é habilitado completamente.  
  
-   O código\-fonte para que seu aplicativo for escrito para a portabilidade completo — recompilando com o símbolo **\_UNICODE** ou o símbolo **\_MBCS** definido, você pode gerar as versões que usam o.  Para obter mais informações, consulte [Mapeamentos de Genérico\- texto em Tchar.h](../Topic/Generic-Text%20Mappings%20in%20Tchar.h.md).  
  
-   O aplicativo usa uma biblioteca wrapper ausente funções de Unicode no Windows 95, Windows 98, e no Windows como ME a descrita em [Criar um único aplicativo Unicode que é executado no Windows 98 e no Windows 2000](http://go.microsoft.com/fwlink/p/?LinkId=250770).  As bibliotecas de invólucro também estão disponíveis comercialmente.  
  
     Você usa funções totalmente portátil, macros, e tipos de dados de tempo de execução C.  A flexibilidade de MFC da suporte a qualquer uma das seguintes estratégias.  
  
 O restante deste tópico destaca a gravação do código totalmente portátil que você pode criar como Unicode ou como MBCS.  
  
## Consulte também  
 [Unicode e MBCS](../text/unicode-and-mbcs.md)   
 [Localidades e páginas de código](../text/locales-and-code-pages.md)