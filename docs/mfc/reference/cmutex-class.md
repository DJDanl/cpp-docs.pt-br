---
title: Classe CMutex | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMutex
- AFXMT/CMutex
- AFXMT/CMutex::CMutex
dev_langs:
- C++
helpviewer_keywords:
- CMutex [MFC], CMutex
ms.assetid: 6330c050-4f01-4195-a099-2029b92f8cf1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f3bde85e64fe8593ec2637e767e8c3c70d3b8200
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37038071"
---
# <a name="cmutex-class"></a>Classe CMutex
Representa um "mutex" — um objeto de sincronização que permite que um thread mutuamente acesse um recurso.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMutex : public CSyncObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMutex::CMutex](#cmutex)|Constrói um objeto `CMutex`.|  
  
## <a name="remarks"></a>Comentários  
 Mutexes são úteis quando apenas um thread por vez pode ter permissão para modificar dados ou algum outro recurso controlado. Por exemplo, adicionando nós a uma lista vinculada é um processo que só deve ser permitido por um segmento por vez. Usando um `CMutex` objeto para controlar a lista vinculada, somente um segmento por vez pode obter acesso à lista.  
  
 Para usar um `CMutex` do objeto, construa o `CMutex` objeto quando ele é necessário. Especifique o nome do mutex deseja aguardar e que seu aplicativo deve possuir inicialmente. Você pode acessar o mutex quando o construtor retorna. Chamar [CSyncObject::Unlock](../../mfc/reference/csyncobject-class.md#unlock) quando você terminar o acesso ao recurso controlado.  
  
 Um método alternativo para o uso de `CMutex` objetos é adicionar uma variável do tipo `CMutex` como um membro de dados para a classe que você deseja controlar. Durante a construção do objeto controlado, chame o construtor do `CMutex` membro de dados especificando se o mutex pertence inicialmente, o nome do mutex (se ele será usado pelos limites do processo) e os atributos de segurança desejados.  
  
 Para acessar os recursos controlados por `CMutex` objetos dessa maneira, primeiro crie uma variável de qualquer tipo [CSingleLock](../../mfc/reference/csinglelock-class.md) ou tipo [CMultiLock](../../mfc/reference/cmultilock-class.md) na função de membro de acesso do recurso. Em seguida, chamar o objeto de bloqueio `Lock` função de membro (por exemplo, [CSingleLock::Lock](../../mfc/reference/csinglelock-class.md#lock)). Neste ponto, o thread será a acessar o recurso, aguarde até que o recurso a ser liberado e obter acesso ou aguarde até que o recurso seja liberado e o tempo limite, Falha ao acessar o recurso. Em qualquer caso, o recurso foi acessado de forma thread-safe. Para liberar o recurso, use o objeto de bloqueio `Unlock` função de membro (por exemplo, [CSingleLock::Unlock](../../mfc/reference/csinglelock-class.md#unlock)), ou permitir que o objeto de bloqueio para que ele esteja fora do escopo.  
  
 Para obter mais informações sobre como usar `CMutex` objetos, consulte o artigo [Multithreading: como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CSyncObject](../../mfc/reference/csyncobject-class.md)  
  
 `CMutex`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmt.h  
  
##  <a name="cmutex"></a>  CMutex::CMutex  
 Constrói uma nomeado ou sem nome `CMutex` objeto.  
  
```  
CMutex(
    BOOL bInitiallyOwn = FALSE,  
    LPCTSTR lpszName = NULL,  
    LPSECURITY_ATTRIBUTES lpsaAttribute = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bInitiallyOwn*  
 Especifica se a criação de thread de `CMutex` inicialmente, o objeto tem acesso ao recurso controlado pelo mutex.  
  
 *lpszName*  
 Nome do objeto de `CMutex` . Se o mutex de outro com o mesmo nome existe, *lpszName* deve ser fornecido se o objeto será usado pelos limites do processo. Se **nulo**, o mutex será sem nome. Se o nome corresponder a um mutex existente, o construtor cria um novo `CMutex` objeto que referencia o mutex esse nome. Se o nome corresponder a um objeto de sincronização existente que não é um mutex, construção falhará.  
  
 *lpsaAttribute*  
 Atributos de segurança para o objeto de mutex. Para obter uma descrição completa dessa estrutura, consulte [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Para acessar ou liberar um `CMutex` de objeto, criar um [CMultiLock](../../mfc/reference/cmultilock-class.md) ou [CSingleLock](../../mfc/reference/csinglelock-class.md) objeto e chame seu [bloqueio](../../mfc/reference/csinglelock-class.md#lock) e [Unlock](../../mfc/reference/csinglelock-class.md#unlock) funções de membro. Se o `CMutex` objeto está sendo usado autônomo, chame seu `Unlock` função de membro para liberá-lo.  
  
> [!IMPORTANT]
>  Depois de criar o `CMutex` de objeto, use [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) para garantir que o mutex ainda não existia. Se o mutex existia inesperadamente, isso pode indicar um processo não autorizado é apropriação indevida e pode ser pretende usar o mutex maliciosamente. Nesse caso, o procedimento sensível à segurança recomendado é fechar o identificador e continuará como se houve uma falha na criação do objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSyncObject](../../mfc/reference/csyncobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



