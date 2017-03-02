---
title: Classe CSemaphore | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSemaphore
dev_langs:
- C++
helpviewer_keywords:
- synchronization objects, semaphores
- CSemaphore class
- semaphores
ms.assetid: 385fc7e4-8f86-4be2-85e1-d23b38c12f7f
caps.latest.revision: 23
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 31de1e553ea2facea6b70c284aecdbf10e22c89f
ms.lasthandoff: 02/25/2017

---
# <a name="csemaphore-class"></a>Classe CSemaphore
Um objeto da classe `CSemaphore` representa um "sinal" — um objeto de sincronização que permite que um número limitado de segmentos em um ou mais processos para acessar um mantém uma contagem do número de threads atualmente acessando um recurso especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSemaphore : public CSyncObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSemaphore::CSemaphore](#csemaphore)|Constrói um objeto `CSemaphore`.|  
  
## <a name="remarks"></a>Comentários  
 Sinais são úteis para controlar o acesso a um recurso compartilhado que suporta apenas um número limitado de usuários. A contagem atual do `CSemaphore` objeto é o número de usuários adicionais permitido. Quando a contagem chega a zero, todas as tentativas de usar o recurso controlado pelo **CSemaphore** objeto será inserido em uma fila do sistema e aguarde até que o tempo limite ou a contagem aumenta acima de 0. O número máximo de usuários que podem acessar o recurso controlado de uma só vez é especificado durante a construção do `CSemaphore` objeto.  
  
 Para usar um **CSemaphore** de objeto, construir o `CSemaphore` objeto quando ele é necessário. Especifique o nome do sinal do qual você deseja aguardar e que seu aplicativo deve possuir inicialmente. Você pode acessar o semáforo quando o construtor retorna. Chamar [CSyncObject::Unlock](../../mfc/reference/csyncobject-class.md#unlock) quando você terminar o acesso ao recurso controlado.  
  
 Um método alternativo para o uso de `CSemaphore` objetos é adicionar uma variável do tipo `CSemaphore` como um membro de dados para a classe que você deseja o controle. Durante a construção do objeto controlado, chame o construtor do `CSemaphore` membro de dados especificando inicial acessar a contagem, contagem máxima de acesso, nome do sinal (se ele será usado nos limites do processo) e os atributos de segurança desejados.  
  
 Para acessar os recursos controlados por `CSemaphore` objetos dessa maneira, primeiro crie uma variável de qualquer tipo [CSingleLock](../../mfc/reference/csinglelock-class.md) ou tipo [CMultiLock](../../mfc/reference/cmultilock-class.md) na função de membro de acesso do recurso. Em seguida, chamar o objeto de bloqueio `Lock` função de membro (por exemplo, [CSingleLock::Lock](../../mfc/reference/csinglelock-class.md#lock)). Neste ponto, o thread será em acessar o recurso, aguarde o recurso a ser lançado e obter acesso ou aguardar o tempo limite, Falha ao acessar o recurso e o recurso a ser liberado. Em qualquer caso, o recurso foi acessado de forma segura para thread. Para liberar o recurso, use o objeto de bloqueio `Unlock` função de membro (por exemplo, [CSingleLock::Unlock](../../mfc/reference/csinglelock-class.md#unlock)), ou permitir que o objeto de bloqueio ficar fora do escopo.  
  
 Como alternativa, você pode criar um **CSemaphore** de objeto independente e acessá-lo explicitamente antes de tentar acessar o recurso controlado. Esse método, ao mesmo tempo mais evidente para alguém que esteja lendo o seu código-fonte, é mais propenso a erros.  
  
 Para obter mais informações sobre como usar **CSemaphore** objetos, consulte o artigo [Multithreading: como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CSyncObject](../../mfc/reference/csyncobject-class.md)  
  
 `CSemaphore`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmt.h  
  
##  <a name="a-namecsemaphorea--csemaphorecsemaphore"></a><a name="csemaphore"></a>CSemaphore::CSemaphore  
 Constrói um nome ou sem nome `CSemaphore` objeto.  
  
```  
CSemaphore(
    LONG lInitialCount = 1,  
    LONG lMaxCount = 1,  
    LPCTSTR pstrName = NULL,  
    LPSECURITY_ATTRIBUTES lpsaAttributes = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lInitialCount*  
 A contagem de uso inicial para o sinal. Deve ser maior ou igual a 0 e menor ou igual a `lMaxCount`.  
  
 `lMaxCount`  
 A contagem de uso máximo para o sinal. Deve ser maior que 0.  
  
 `pstrName`  
 O nome do sinal do. Deve ser fornecido se o sinal será acessado pelos limites do processo. Se `NULL,` o objeto será sem nome. Se o nome corresponde a um sinal existente, o construtor cria um novo `CSemaphore` objeto que referencia o sinal do nome. Se o nome corresponde a um objeto de sincronização existente que não seja um sinal, a construção falhará.  
  
 *lpsaAttributes*  
 Atributos de segurança para o objeto de semáforo. Para obter uma descrição completa dessa estrutura, consulte [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Para acessar ou liberar um `CSemaphore` de objeto, criar um [CMultiLock](../../mfc/reference/cmultilock-class.md) ou [CSingleLock](../../mfc/reference/csinglelock-class.md) objeto e chamar seu [bloqueio](../../mfc/reference/csinglelock-class.md#lock) e [Unlock](../../mfc/reference/csinglelock-class.md#unlock) funções de membro.  
  
> [!IMPORTANT]
>  Depois de criar o `CSemaphore` de objeto, use [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) para garantir que o mutex ainda não existir. Se o mutex existia inesperadamente, isso pode indicar um processo não autorizado é apropriação indevida e pode ser pretende usar o mutex de maneira mal-intencionada. Nesse caso, o procedimento sensível à segurança recomendado é fechar o identificador e continuará como se houve uma falha na criação do objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSyncObject](../../mfc/reference/csyncobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




