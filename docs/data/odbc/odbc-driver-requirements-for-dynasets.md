---
title: "Requisitos de driver ODBC para dynasets | Microsoft Docs"
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
  - "drivers, para dynasets"
  - "drivers, ODBC"
  - "dynasets"
  - "Drivers ODBC, dynasets"
  - "conjunto de registros ODBC, dynasets"
  - "conjuntos de registros, dynasets"
ms.assetid: 585cc67b-4d92-404b-9903-d769cd17badc
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Requisitos de driver ODBC para dynasets
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Nas classes da base de dados de MFC ODBC, os dynasets são conjuntos de registros com propriedades dinâmicos; permanecem sincronizados com a fonte de dados em algumas formas.  Os dynasets MFC \(mas os conjuntos de registros não somente avanço\) exigem um driver ODBC com conformidade de API de nível 2.  Se o driver para seu [fonte de dados](../../data/odbc/data-source-odbc.md) está em conformidade com o nível 1 API definido, você ainda pode usar instantâneos atualizável e somente leitura e conjuntos de registros de somente avanço, mas não dynasets.  No entanto, um driver de nível 1 pode dar suporte a dynasets se ele da suporte à busca estendida e os cursores controlados por conjunto de chaves.  
  
 Na terminologia de ODBC, os dynasets e os instantâneos são chamados de cursores.  Um cursor é um mecanismo usado mantendo o controle de sua posição em um conjunto de registros.  Para obter mais informações sobre os requisitos de driver para dynasets, consulte [Dynaset](../../data/odbc/dynaset.md).  Para obter mais informações sobre os cursores, consulte [ODBC \(ODBC\)](https://msdn.microsoft.com/en-us/library/ms710252.aspx) na documentação do SDK do MSDN.  
  
> [!NOTE]
>  Para conjuntos de registros atualizável, o driver ODBC deve oferecer suporte a instruções posicionadas de atualização ou função de API ODBC de **::SQLSetPos** .  Se ambos têm suporte, o **::SQLSetPos** MFC usa para maior eficiência.  Alternativamente, para instantâneos, você pode usar a biblioteca de cursores, que fornece suporte necessário para instantâneos atualizável \(cursores estáticos e instruções posicionadas de atualização\).  
  
## Consulte também  
 [Noções básicas de ODBC](../../data/odbc/odbc-basics.md)