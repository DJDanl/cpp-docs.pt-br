---
title: "Classe de CSemaphore | Microsoft Docs"
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
  - "CSemaphore"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSemaphore"
  - "semáforos"
  - "objetos de sincronização, semáforos"
ms.assetid: 385fc7e4-8f86-4be2-85e1-d23b38c12f7f
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSemaphore
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um objeto da classe `CSemaphore` representa um “semáforo” — um objeto de sincronização que permite que um número limitado de segmentos em um ou vários processos acesse a mantém uma contagem do número de segmentos que acessam atualmente um recurso especificado.  
  
## Sintaxe  
  
```  
class CSemaphore : public CSyncObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSemaphore::CSemaphore](../Topic/CSemaphore::CSemaphore.md)|Constrói um objeto de `CSemaphore` .|  
  
## Comentários  
 Os semáforos são úteis no controle de acesso a um recurso compartilhado que só possa oferecer suporte a um número limitado de usuários.  A contagem atual do objeto de `CSemaphore` é o número de usuários adicionais permitidos.  Quando a contagem atinge zero, qualquer tentativa de usar o recurso controlado pelo objeto de **CSemaphore** serão inseridas em uma fila e uma espera do sistema até o tempo limite ou as elevações de contagem acima de 0.  O número máximo de usuários que podem acessar o recurso controlado ao mesmo tempo é especificado durante a compilação do objeto de `CSemaphore` .  
  
 Para usar um objeto de **CSemaphore** , construir o objeto de `CSemaphore` quando necessário.  Especifique o nome de semáforo que você deseja aguardar no, e que seu aplicativo deve possuir o inicialmente.  Você pode acessar o semáforo quando o construtor retorna.  Chame [CSyncObject::Unlock](../Topic/CSyncObject::Unlock.md) quando você terminar ao acessar o recurso controlado.  
  
 Um método alternativo para usar objetos de `CSemaphore` é adicionar uma variável do tipo `CSemaphore` como um membro de dados para a classe que você deseja controlar.  Durante a compilação do objeto controlada, chamar o construtor do membro de dados de `CSemaphore` que especifica o número inicial de acesso, o número máximo de acesso, o nome de semáforo \(se será usado fora dos limites de processo\), e atributos de segurança desejados.  
  
 Para acessar os recursos controlados por objetos de `CSemaphore` de essa maneira, principalmente para criar uma variável do tipo [CSingleLock](../../mfc/reference/csinglelock-class.md) ou para digite [CMultiLock](../../mfc/reference/cmultilock-class.md) na função de membro de acesso do recurso.  Chame a função de membro de `Lock` do objeto de bloqueio \(por exemplo, [CSingleLock::Lock](../Topic/CSingleLock::Lock.md)\).  Em este ponto, o segmento acederá ao recurso espera, para que o recurso seja liberado e acederá, ou esperará o recurso a ser liberados e o tempo limite, não obtiver acesso ao recurso.  Em qualquer caso, o recurso foi acessado de uma maneira segura.  Para liberar o recurso, usar a função de membro de `Unlock` do objeto de bloqueio \(por exemplo, [CSingleLock::Unlock](../Topic/CSingleLock::Unlock.md)\), ou permitir o objeto de bloqueio para queda fora do escopo.  
  
 Como alternativa, você pode criar um objeto de **CSemaphore** autônomo, e acessá\-lo explicitamente antes de tentar acessar o recurso controlado.  Esse método, quando esclarecedor a alguém que lê seu código\-fonte, é um erro propenso.  
  
 Para obter mais informações sobre como usar objetos de **CSemaphore** , consulte o artigo [multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CSyncObject](../../mfc/reference/csyncobject-class.md)  
  
 `CSemaphore`  
  
## Requisitos  
 **Cabeçalho:** afxmt.h  
  
## Consulte também  
 [Classe de CSyncObject](../../mfc/reference/csyncobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)