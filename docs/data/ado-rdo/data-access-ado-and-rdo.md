---
title: "Acesso a dados: ADO e RDO | Microsoft Docs"
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
  - "controles associados [C++], ADO"
  - "controles associados [C++], RDO"
  - "controles [C++], associação de dados"
  - "acesso a dados [C++], Controles de dados RDO"
  - "associação de dados [C++], ADO"
  - "associação de dados [C++], RDO"
  - "controles de dados [C++]"
  - "controles de dados associados [C++], ADO"
  - "controles de dados associados [C++], RDO"
ms.assetid: 92da8f1e-144b-4605-ac0a-43c25bdc14a7
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Acesso a dados: ADO e RDO
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir mostra duas tecnologias subjacentes que dão suporte à fonte de dados ou controles vinculadas a dados.  
  
 **ADO**  
 ADO é um wrapper de COM OLE DB que facilita gravar aplicativos de acesso a dados \(consumidores\).  OLE DB é uma tecnologia universal baseado em COM de acesso a dados, permitindo usar qualquer fonte de dados, métodos de acesso não apenas indexados, sequenciais \(ISAM\) e bases de dados com base em SQL.  
  
 Os provedores OLE DB podem acessar dados de uma variedade de fontes de dados e não são limitados para consultas SQL para recuperar dados e sim podem usar consultas conforme definido no provedor.  
  
 **RDO**  
 RDO é o wrapper de COM ODBC.  ODBC c, API com base no, permite acesso a dados heterogênea \(\) de uso geral.  No entanto, RDO depende do SQL como o idioma de comando para acessar dados.  
  
 Você poderia usar os controles de acesso a dados ADO\- com base em vez dos controles de acesso a dados de RDO.  
  
 A tabela a seguir mostra as principais diferenças entre controles de dados ADO e de RDO.  
  
 **Controles associados a dados**  
 Os controles vinculadas a dados de RDO usam as interfaces de **ICursor** ; Os controles ADO usam a interface OLE DB `IRowset` .  Em ambos os casos, as interfaces usadas pelos controles retornam um conjunto de linhas.  
  
 Os controles vinculadas a dados baseados RDO\- foram criados para funcionar com melhor o Visual Basic.  Como tal, alguma funcionalidade de controles vinculadas a dados de RDO, especialmente na formatação, não está disponível em aplicativos do Visual C\+\+.  Esse problema não estiver presente no ADO que databinding controles.  
  
 **Controles de dados**  
 Os controles de dados ADO implementam a interface de **IDataSource** e os controles de dados de RDO implementam a interface de **IVBDSC** .  Você pode chamar um método de **IDataSource** para receber um ponteiro de interface de `IRowset` .  Da mesma forma, você pode chamar um método de IVBDSC para obter um ponteiro de interface de **ICursor** .  
  
## Consulte também  
 [Vinculação de dados com controles ActiveX no Visual C\+\+](../../data/ado-rdo/databinding-with-activex-controls-in-visual-cpp.md)