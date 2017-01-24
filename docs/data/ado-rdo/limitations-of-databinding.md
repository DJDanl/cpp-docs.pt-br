---
title: "Limita&#231;&#245;es de associa&#231;&#227;o de dados | Microsoft Docs"
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
  - "associação de dados [C++], limitações no Visual C++"
ms.assetid: 376d7738-5252-4caa-adda-a5486ab2a2a2
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Limita&#231;&#245;es de associa&#231;&#227;o de dados
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Databinding é um modo avançado de criar rapidamente aplicativos de dados.  No entanto, a arquitetura databinding de controles da camada atual é inerentemente dois.  
  
## Escalabilidade  
 Os controles vinculadas a dados ADO podem acessar apenas dados de controle de dados ADO.  Os controles vinculadas a dados de RDO só podem acessar dados de controle de RemoteData RDO.  Para o controle de RemoteData RDO, não há uma solução alternativa para usar uma arquitetura de duas camadas, que leva ao servidor de base de dados que recebe todas as solicitações de recuperação de dados diretamente.  Para evitar diretamente se conectar ao servidor de base de dados, grave um provedor que permite o acesso a empresa da camada intermediária e aos objetos de dados.  O controle de dados ADO se conecta a esses objetos, em vez do servidor de base de dados.  Esses objetos da camada intermediária podem ser armazenados em cachê e gerenciados em um servidor da transação como serviços COM\+ 1,0.  
  
## Controle de versão e distribuição  
 Quando novas versões de controles são liberadas, o aplicativo precisará ser testado pelas novas versões.  Se outro aplicativo estiver instalado no computador de um usuário, e tiver uma versão diferente dos controles, o aplicativo precisará ser verificado.  Finalmente, quando novas versões de controles são liberadas, os novos controles terão que ser distribuídos para usuários do aplicativo.  
  
 **Drivers e provedores**  
  
 Databinding é tão bem como o driver ODBC ou o provedor OLE DB que você está usando.  Como os drivers e os provedores são responsáveis para expor dados nos controles de dados, é importante assegurar que o driver ou o provedor ofereçam suporte à funcionalidade que você precisa.  Quando você seleciona um driver ou um provedor, você também deve assegurar que os usuários tenham o driver ou o provedor instalado.  Isso inclui instalar qualquer middleware que o driver ou o provedor requeira.  Por exemplo, para conectividade ODBC Oracle, o usuário deve ter instalado não apenas um driver ODBC do Oracle, mas também o middleware do Oracle.  Para conectividade aos servidores do Oracle 7.3, o driver ODBC do Microsoft Oracle é recomendado.  
  
 **Programação**  
  
 Como os controles ActiveX foi criado para ser componentes da caixa negra, programabilidade é limitado ao acesso de um desenvolvedor às interfaces de controle.  No modelo databinding no publicador de recursos, isso é implementado com [classes wrapper](../../data/ado-rdo/wrapper-classes.md) gerada pelo assistente de controle ActiveX de inserção.  Se o assistente não poderá detectar coclass, nenhuma classe de invólucro é gerada e não há nenhum acesso programático.  
  
 Apesar dessas restrições, databinding tem recursos para um modo rapidamente os aplicativos de dados de protótipo usando o Visual C\+\+.  Se a velocidade de desenvolvimento, é importante databinding deve ser considerado ao criar seu aplicativo.  
  
## Consulte também  
 [Vinculação de dados com controles ActiveX no Visual C\+\+](../../data/ado-rdo/databinding-with-activex-controls-in-visual-cpp.md)