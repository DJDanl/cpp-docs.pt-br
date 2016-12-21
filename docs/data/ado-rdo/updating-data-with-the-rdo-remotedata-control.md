---
title: "Atualizando dados com o controle RemoteData RDO | Microsoft Docs"
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
  - "Controle RemoteData RDO"
  - "Controle RemoteData RDO, atualizando dados"
  - "Controle RemoteData"
  - "Controle RemoteData, atualizando dados"
ms.assetid: abb4175f-612e-4645-905e-c0fa918b0fd7
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atualizando dados com o controle RemoteData RDO
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os dados de controle de RemoteData RDO podem ser somente leitura ou modificáveis.  
  
### Para criar um aplicativo que modifica dados usando o controle de RemoteData RDO  
  
1.  Defina a propriedade de **CursorDriver** de controle de RemoteData RDO.  
  
    -   O repositório lateral de cursores de servidor retornou dados no servidor.  
  
    -   Os cursores do lado do cliente ODBC armazenam os dados no armazenamento local do cliente.  
  
    -   Os cursores do lado do lote do cliente usam uma biblioteca de cursores criada para tratar problemas de simultaneidade.  
  
    -   Nenhuma opção de cursor é usada quando uma consulta ação é executada, e assim nenhum cursor é necessário.  
  
2.  Defina a propriedade de **LockType** de controle de RemoteData RDO.  A simultaneidade otimista baseada na opção de resultados é recomendada.  
  
    -   A simultaneidade somente leitura não deve ser usada se você quiser dados para ser modificado.  
  
    -   A simultaneidade pessimista bloqueia dados durante a atualização de forma que outros usuários não estão em perigo de confirmar alterações incompatíveis de dados.  
  
    -   A simultaneidade otimista não bloqueia dados, mas se durante a confirmação, o detecta que outro cliente postou um estado incompatível, o controle de RemoteData RDO gerencie um erro.  
  
3.  Defina a propriedade de **ResultsetType** de controle de RemoteData RDO.  Verifique se o driver ODBC da suporte às opções escolhidas:  
  
    -   Quando cria o cursor estático é escolhido, as alterações não são detectadas até que o cursor seja fechado e reaberto.  
  
    -   Quando cria o cursor controlado por conjunto de chaves é escolhido, o cursor permite inserções, atualizações, exclusões e, no, no próprio cursor de conjunto de chaves.  
  
4.  Definir o controle associada a dados quando necessário para permitir que o updateability.  Observe que alguns controles não permitem atualizar.  
  
 Para obter mais informações sobre como usar esses objetos, consulte a documentação sobre o controle de RemoteData RDO.  
  
## Consulte também  
 [Associação de dados RDO](../../data/ado-rdo/rdo-databinding.md)   
 [Usando vinculação de dados RDO no Visual C\+\+](../../data/ado-rdo/using-rdo-databinding-in-visual-cpp.md)