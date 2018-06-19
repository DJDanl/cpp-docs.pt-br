---
title: Classe CSemaphore | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CSemaphore
- AFXMT/CSemaphore
- AFXMT/CSemaphore::CSemaphore
dev_langs:
- C++
helpviewer_keywords:
- CSemaphore [MFC], CSemaphore
ms.assetid: 385fc7e4-8f86-4be2-85e1-d23b38c12f7f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2f3c5f7cb354bb4889c528fc55459eabcb032709
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33369171"
---
# <a name="csemaphore-class"></a>Classe CSemaphore
Um objeto da classe `CSemaphore` representa um "semáforo" — um objeto de sincronização que permite que um número limitado de threads em um ou mais processos para acessar um mantém uma contagem do número de threads atualmente acessando um recurso especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSemaphore : public CSyncObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSemaphore::CSemaphore](#csemaphore)|Constrói um objeto `CSemaphore`.|  
  
## <a name="remarks"></a>Comentários  
 Semáforos são úteis para controlar o acesso a um recurso compartilhado que só pode oferecer suporte a um número limitado de usuários. A contagem atual do `CSemaphore` objeto é o número de usuários adicionais permitido. Quando a contagem atinge zero, todas as tentativas de usar o recurso controlado pelo **CSemaphore** objeto será inserido em uma fila do sistema e aguarde até que o tempo limite ou a contagem se eleva acima de 0. O número máximo de usuários que podem acessar o recurso controlado por vez é especificado durante a construção do `CSemaphore` objeto.  
  
 Para usar um **CSemaphore** do objeto, construa o `CSemaphore` objeto quando ele é necessário. Especifique o nome do sinal do qual você deseja aguardar e que seu aplicativo deve possuir inicialmente. Você pode acessar o semáforo quando o construtor retorna. Chamar [CSyncObject::Unlock](../../mfc/reference/csyncobject-class.md#unlock) quando você terminar o acesso ao recurso controlado.  
  
 Um método alternativo para o uso de `CSemaphore` objetos é adicionar uma variável do tipo `CSemaphore` como um membro de dados para a classe que você deseja controlar. Durante a construção do objeto controlado, chame o construtor do `CSemaphore` membro de dados especificando inicial acessar contagem, contagem máxima de acesso, o nome do sinal (se ele será usado pelos limites do processo) e os atributos de segurança desejados.  
  
 Para acessar os recursos controlados por `CSemaphore` objetos dessa maneira, primeiro crie uma variável de qualquer tipo [CSingleLock](../../mfc/reference/csinglelock-class.md) ou tipo [CMultiLock](../../mfc/reference/cmultilock-class.md) na função de membro de acesso do recurso. Em seguida, chamar o objeto de bloqueio `Lock` função de membro (por exemplo, [CSingleLock::Lock](../../mfc/reference/csinglelock-class.md#lock)). Neste ponto, o thread será a acessar o recurso, aguarde até que o recurso a ser liberado e obter acesso ou aguarde até que o recurso seja liberado e o tempo limite, Falha ao acessar o recurso. Em qualquer caso, o recurso foi acessado de forma thread-safe. Para liberar o recurso, use o objeto de bloqueio `Unlock` função de membro (por exemplo, [CSingleLock::Unlock](../../mfc/reference/csinglelock-class.md#unlock)), ou permitir que o objeto de bloqueio para que ele esteja fora do escopo.  
  
 Como alternativa, você pode criar um **CSemaphore** objeto autônomo e acessá-lo explicitamente antes de tentar acessar o recurso controlado. Esse método, ao mesmo tempo mais evidente a alguém ler seu código-fonte, é mais propenso a erros.  
  
 Para obter mais informações sobre como usar **CSemaphore** objetos, consulte o artigo [Multithreading: como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CSyncObject](../../mfc/reference/csyncobject-class.md)  
  
 `CSemaphore`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmt.h  
  
##  <a name="csemaphore"></a>  CSemaphore::CSemaphore  
 Constrói uma nomeado ou sem nome `CSemaphore` objeto.  
  
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
 O nome do sinal do. Deve ser fornecido se o sinal será acessado pelos limites do processo. Se `NULL`, o objeto será sem nome. Se o nome corresponder a um semáforo existente, o construtor cria um novo `CSemaphore` objeto que referencia o sinal do nome. Se o nome corresponder a um objeto de sincronização existente que não é um sinal, a construção falhará.  
  
 *lpsaAttributes*  
 Atributos de segurança para o objeto de semáforo. Para obter uma descrição completa dessa estrutura, consulte [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Para acessar ou liberar um `CSemaphore` de objeto, criar um [CMultiLock](../../mfc/reference/cmultilock-class.md) ou [CSingleLock](../../mfc/reference/csinglelock-class.md) objeto e chame seu [bloqueio](../../mfc/reference/csinglelock-class.md#lock) e [Unlock](../../mfc/reference/csinglelock-class.md#unlock) funções de membro.  
  
> [!IMPORTANT]
>  Depois de criar o `CSemaphore` de objeto, use [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) para garantir que o mutex ainda não existia. Se o mutex existia inesperadamente, isso pode indicar um processo não autorizado é apropriação indevida e pode ser pretende usar o mutex maliciosamente. Nesse caso, o procedimento sensível à segurança recomendado é fechar o identificador e continuará como se houve uma falha na criação do objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSyncObject](../../mfc/reference/csyncobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



