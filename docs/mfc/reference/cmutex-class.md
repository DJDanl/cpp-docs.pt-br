---
title: "Classe de CMutex | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "Mutex"
  - "CMutex"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMutex"
  - "mutex"
  - "classes de sincronização, Classe de CMutex"
  - "objetos de sincronização, mutex"
ms.assetid: 6330c050-4f01-4195-a099-2029b92f8cf1
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMutex
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa um “mutex” — um objeto de sincronização que permite a um segmento mutuamente exclusivos o acesso a um recurso.  
  
## Sintaxe  
  
```  
class CMutex : public CSyncObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMutex::CMutex](../Topic/CMutex::CMutex.md)|Constrói um objeto de `CMutex` .|  
  
## Comentários  
 Mutexes é útil quando apenas um segmento de cada vez pode ser permitido modificar dados ou outro recurso controlado.  Por exemplo, adicionar nós a uma lista vinculada é um processo que deve ser apenas permitido por um segmento de cada vez.  Usando um objeto de `CMutex` para controlar a lista vinculada, apenas um segmento de cada vez pode obter acesso à lista.  
  
 Para usar um objeto de `CMutex` , construir o objeto de `CMutex` quando necessário.  Especifique o nome mutex que você deseja aguardar no, e que seu aplicativo deve possuir o inicialmente.  Você pode acessar o mutex quando o construtor retorna.  Chame [CSyncObject::Unlock](../Topic/CSyncObject::Unlock.md) quando você terminar ao acessar o recurso controlado.  
  
 Um método alternativo para usar objetos de `CMutex` é adicionar uma variável do tipo `CMutex` como um membro de dados para a classe que você deseja controlar.  Durante a compilação do objeto controlada, chamar o construtor de especificar o membro de dados de `CMutex` se o mutex é pertencente inicialmente, o nome mutex \(se será usado fora dos limites de processo\), e atributos de segurança desejados.  
  
 Para acessar os recursos controlados por objetos de `CMutex` de essa maneira, principalmente para criar uma variável do tipo [CSingleLock](../../mfc/reference/csinglelock-class.md) ou para digite [CMultiLock](../../mfc/reference/cmultilock-class.md) na função de membro de acesso do recurso.  Chame a função de membro de `Lock` do objeto de bloqueio \(por exemplo, [CSingleLock::Lock](../Topic/CSingleLock::Lock.md)\).  Em este ponto, o segmento acederá ao recurso espera, para que o recurso seja liberado e acederá, ou esperará o recurso a ser liberados e o tempo limite, não obtiver acesso ao recurso.  Em qualquer caso, o recurso foi acessado de uma maneira segura.  Para liberar o recurso, usar a função de membro de `Unlock` do objeto de bloqueio \(por exemplo, [CSingleLock::Unlock](../Topic/CSingleLock::Unlock.md)\), ou permitir o objeto de bloqueio para queda fora do escopo.  
  
 Para obter mais informações sobre como usar objetos de `CMutex` , consulte o artigo [multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CSyncObject](../../mfc/reference/csyncobject-class.md)  
  
 `CMutex`  
  
## Requisitos  
 **Cabeçalho:** afxmt.h  
  
## Consulte também  
 [Classe de CSyncObject](../../mfc/reference/csyncobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)