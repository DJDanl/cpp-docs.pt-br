---
title: "Estrutura CDaoRelationFieldInfo | Microsoft Docs"
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
  - "CDaoRelationFieldInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura CDaoRelationFieldInfo"
  - "DAO (Objetos de Acesso a Dados), Coleção de relações"
ms.assetid: 47cb89ca-dc80-47ce-96fd-cc4b88512558
caps.latest.revision: 13
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura CDaoRelationFieldInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `CDaoRelationFieldInfo` contém informações sobre um campo em uma relação definida para objetos \(DAO\) de acesso a dados.  
  
## Sintaxe  
  
```  
  
      struct CDaoRelationFieldInfo  
{  
   CString m_strName;           // Primary  
   CString m_strForeignName;    // Primary  
};  
```  
  
#### Parâmetros  
 `m_strName`  
 O nome do campo na tabela primária da relação.  
  
 `m_strForeignName`  
 O nome do campo na tabela estrangeira da relação.  
  
## Comentários  
 Um objeto da relação de DAO especifica os campos em uma tabela primária e os campos em uma tabela estrangeira que definem a relação.  As referências a primário na definição de estrutura anterior indicam como as informações são retornadas no membro de `m_pFieldInfos` de um objeto de [CDaoRelationInfo](../Topic/CDaoRelationInfo%20Structure.md) obtido chamando a função de membro de [GetRelationInfo](../Topic/CDaoDatabase::GetRelationInfo.md) da classe `CDaoDatabase`.  
  
 Os objetos de relação e os objetos de campo da relação não são representados por uma classe de MFC.  Em vez disso, os objetos de DAO que são a base de objetos MFC da classe [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) contém uma coleção de objetos de relação, chamada a coleção de relações.  Cada objeto de relação, por sua vez, contém uma coleção de objetos de campo da relação.  Cada objeto do campo da relação correlaciona um campo na tabela primária com um campo na tabela estrangeira.  Feitos em conjunto, os objetos de campo da relação definem um grupo de campos em cada tabela, que definem junto a relação.  `CDaoDatabase` permite acessar objetos de relação com `CDaoRelationInfo` para o objeto chamando a função de membro de `GetRelationInfo` .  O objeto de `CDaoRelationInfo` , em seguida, tem um membro de dados, `m_pFieldInfos`, que aponte para uma matriz de objetos de `CDaoRelationFieldInfo` .  
  
 Chame a função de membro de [GetRelationInfo](../Topic/CDaoDatabase::GetRelationInfo.md) do objeto contentor de `CDaoDatabase` cujas relações na coleção é armazenada o objeto da relação que você está interessado.  Acessar no membro de `m_pFieldInfos` do objeto de [CDaoRelationInfo](../Topic/CDaoRelationInfo%20Structure.md) .  `CDaoRelationFieldInfo` também define uma função de membro de `Dump` em construções de depuração.  Você pode usar para `Dump` despejar os conteúdos de um objeto de `CDaoRelationFieldInfo` .  
  
## Requisitos  
 **Header:** afxdao.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Estrutura CDaoRelationInfo](../Topic/CDaoRelationInfo%20Structure.md)