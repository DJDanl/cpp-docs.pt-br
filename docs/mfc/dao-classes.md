---
title: Classes DAO | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.classes.data
dev_langs:
- C++
helpviewer_keywords:
- database classes [MFC], DAO
- DAO [MFC], classes
ms.assetid: b15d0cd6-328b-4288-9c19-d037a795db57
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c80351071318b88956fa3717875561bdf30232dc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dao-classes"></a>Classes DAO
Essas classes de trabalhar com as outras classes de estrutura de aplicativo para fornecer acesso fácil a bancos de dados do objeto de acesso a dados (DAO), que usam o mesmo mecanismo de banco de dados do Microsoft Visual Basic e Microsoft Access. As classes DAO também podem acessar uma ampla variedade de bancos de dados para os quais os drivers de conectividade de banco de dados aberto (ODBC) estão disponíveis.  
  
 Programas que usam bancos de dados DAO terá pelo menos um `CDaoDatabase` objeto e um `CDaoRecordset` objeto.  
  
> [!NOTE]
>  Os assistentes e o ambiente do Visual C++ não suportam DAO (embora as classes DAO estão incluídas e você ainda pode usá-los). A Microsoft recomenda que você use o ODBC para novos projetos MFC. Você só deve usar DAO na manutenção de aplicativos existentes.  
  
 [CDaoWorkspace](../mfc/reference/cdaoworkspace-class.md)  
 Gerencia uma sessão de banco de dados nomeado e protegido por senha de logon para fazer logoff. A maioria dos programas usar o espaço de trabalho padrão.  
  
 [CDaoDatabase](../mfc/reference/cdaodatabase-class.md)  
 Uma conexão para um banco de dados por meio do qual você pode operar nos dados.  
  
 [CDaoRecordset](../mfc/reference/cdaorecordset-class.md)  
 Representa um conjunto de registros selecionados de uma fonte de dados.  
  
 [CDaoRecordView](../mfc/reference/cdaorecordview-class.md)  
 Uma exibição que mostra os registros do banco de dados em controles.  
  
 [CDaoQueryDef](../mfc/reference/cdaoquerydef-class.md)  
 Representa uma definição de consulta, normalmente um salvo em um banco de dados.  
  
 [CDaoTableDef](../mfc/reference/cdaotabledef-class.md)  
 Representa a definição armazenada de uma tabela base ou uma tabela anexada.  
  
 [CDaoException](../mfc/reference/cdaoexception-class.md)  
 Representa uma condição de exceção decorrentes das classes DAO.  
  
 [CDaoFieldExchange](../mfc/reference/cdaofieldexchange-class.md)  
 Oferece suporte as rotinas de troca (DFX) dos campos de registro DAO usadas pelas classes de banco de dados DAO. Você normalmente não diretamente usará essa classe.  
  
## <a name="related-classes"></a>Classes relacionadas  
 [CLongBinary](../mfc/reference/clongbinary-class.md)  
 Encapsula um identificador para o armazenamento para um objeto binário grande (BLOB), como um bitmap. `CLongBinary`objetos são usados para gerenciar objetos de grandes dados armazenados nas tabelas de banco de dados.  
  
 [COleCurrency](../mfc/reference/colecurrency-class.md)  
 Wrapper para o tipo de automação OLE **moeda**, um tipo aritmético de ponto fixo, com 15 dígitos antes do ponto decimal e 4 dígitos após.  
  
 [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md)  
 Wrapper para o tipo de automação OLE **data**. Representa os valores de data e hora.  
  
 [COleVariant](../mfc/reference/colevariant-class.md)  
 Wrapper para o tipo de automação OLE **VARIANT**. Dados em **VARIANT**s podem ser armazenados em vários formatos.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

