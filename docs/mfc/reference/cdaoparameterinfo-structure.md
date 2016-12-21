---
title: "Estrutura CDaoParameterInfo | Microsoft Docs"
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
  - "CDaoParameterInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura CDaoParameterInfo"
  - "DAO (Objetos de Acesso a Dados), Coleção de parâmetros"
ms.assetid: 45fd53cd-cb84-4e12-b48d-7f2979f898ad
caps.latest.revision: 13
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura CDaoParameterInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `CDaoParameterInfo` contém informações sobre um objeto do parâmetro definido para objetos \(DAO\) de acesso a dados.  
  
## Sintaxe  
  
```  
  
      struct CDaoParameterInfo  
{  
   CString m_strName;       // Primary  
   short m_nType;           // Primary  
   ColeVariant m_varValue;  // Secondary  
};  
```  
  
#### Parâmetros  
 `m_strName`  
 Nomear exclusivamente o objeto de parâmetro.  Para obter mais informações, consulte o tópico “propriedade nome” na ajuda de DAO.  
  
 `m_nType`  
 Um valor que indica o tipo de dados de um objeto de parâmetro.  Para obter uma lista de valores possíveis, consulte o membro de `m_nType` da estrutura de [CDaoFieldInfo](../Topic/CDaoFieldInfo%20Structure.md) .  Para obter mais informações, consulte o tópico “propriedade tipo” na ajuda de DAO.  
  
 *m\_varValue*  
 O valor do parâmetro, armazenado em um objeto de [COleVariant](../../mfc/reference/colevariant-class.md) .  
  
## Comentários  
 As referências a acima primário e secundário indicam como as informações são retornadas pela função de membro de [GetParameterInfo](../Topic/CDaoQueryDef::GetParameterInfo.md) na classe `CDaoQueryDef`.  
  
 O MFC não encapsula objetos de parâmetro de DAO em uma classe.  Os objetos de querydef de DAO que são a base de objetos MFC `CDaoQueryDef` armazenam parâmetros em suas coleções de parâmetros.  Para acessar os objetos de parâmetro em [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) objeto, chame a função de membro de `GetParameterInfo` do objeto de querydef para um nome de parâmetro específico ou um índice na coleção de parâmetros.  Você pode usar a função de membro de [CDaoQueryDef::GetParameterCount](../Topic/CDaoQueryDef::GetParameterCount.md) junto com `GetParameterInfo` para criar um loop através da coleção de parâmetros.  
  
 As informações recuperadas pela função de membro de [CDaoQueryDef::GetParameterInfo](../Topic/CDaoQueryDef::GetParameterInfo.md) são armazenadas em uma estrutura de `CDaoParameterInfo` .  Chame `GetParameterInfo` para o objeto de querydef cuja na coleção de parâmetros o objeto do parâmetro é armazenado.  
  
> [!NOTE]
>  Se você quiser obter ou definir apenas o valor de um parâmetro, use as funções de membro de [GetParamValue](../Topic/CDaoRecordset::GetParamValue.md) e de [SetParamValue](../Topic/CDaoRecordset::SetParamValue.md) da classe `CDaoRecordset`.  
  
 `CDaoParameterInfo` também define uma função de membro de `Dump` em construções de depuração.  Você pode usar para `Dump` despejar os conteúdos de um objeto de `CDaoParameterInfo` .  
  
## Requisitos  
 **Header:** afxdao.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe de CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)