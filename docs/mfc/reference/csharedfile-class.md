---
title: Classe CSharedFile | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSharedFile
- AFXADV/CSharedFile
- AFXADV/CSharedFile::CSharedFile
- AFXADV/CSharedFile::Detach
- AFXADV/CSharedFile::SetHandle
dev_langs:
- C++
helpviewer_keywords:
- memory files
- CSharedFile class
- shared memory files
ms.assetid: 5d000422-9ede-4318-a8c9-f7412b674f39
caps.latest.revision: 21
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: f812b2c7b8e3b158068bf3fdab0a327460056251
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="csharedfile-class"></a>Classe CSharedFile
O [CMemFile](../../mfc/reference/cmemfile-class.md)-compartilhado de classe derivada que oferece suporte a arquivos de memória.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSharedFile : public CMemFile  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSharedFile::CSharedFile](#csharedfile)|Constrói um objeto `CSharedFile`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSharedFile::Detach](#detach)|Fecha o arquivo de memória compartilhada e retorna o identificador do seu bloco de memória.|  
|[CSharedFile::SetHandle](#sethandle)|Anexa o arquivo de memória compartilhada para um bloco de memória.|  
  
## <a name="remarks"></a>Comentários  
 Arquivos de memória se comportam como arquivos do disco, exceto que o arquivo é armazenado na RAM, e não no disco. Um arquivo de memória é útil para armazenamento temporário rápida ou transferir os bytes brutos ou serializado objetos entre processos independentes.  
  
 Arquivos de memória compartilhada são diferentes de outros arquivos de memória é alocada memória para eles com o [GlobalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366574) função do Windows. O `CSharedFile` classe armazena dados em um bloco de memória alocada globalmente (criada usando **GlobalAlloc**), e este bloco de memória pode ser compartilhado usando DDE, a área de transferência ou outras OLE/COM operações de transferência uniforme de dados, de, por exemplo, usando `IDataObject`.  
  
 **GlobalAlloc** retorna um `HGLOBAL` tratar em vez de um ponteiro de memória, como o ponteiro retornado por [malloc](../../c-runtime-library/reference/malloc.md). O `HGLOBAL` identificador é necessária em determinados aplicativos. Por exemplo, para colocar dados na área de transferência é necessário um `HGLOBAL` tratar.  
  
 Observe que `CSharedFile` não arquivos mapeados na memória de uso e os dados não podem ser compartilhados diretamente entre processos.  
  
 `CSharedFile`objetos podem alocar automaticamente sua própria memória ou você pode anexar seu próprio bloco de memória para o `CSharedFile` chamando [CSharedFile::SetHandle](#sethandle). Em ambos os casos, a memória para expandir o arquivo de memória automaticamente é alocada em `nGrowBytes`-em incrementos de tamanho se `nGrowBytes` não for zero.  
  
 Para obter mais informações, consulte o artigo [arquivos no MFC](../../mfc/files-in-mfc.md) e [manuseio de arquivos](../../c-runtime-library/file-handling.md) no *referência da biblioteca de tempo de execução*.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 [CMemFile](../../mfc/reference/cmemfile-class.md)  
  
 `CSharedFile`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxadv.h  
  
##  <a name="csharedfile"></a>CSharedFile::CSharedFile  
 Constrói um `CSharedFile` object e aloca memória para ele.  
  
```  
CSharedFile(
    UINT nAllocFlags = GMEM_DDESHARE | GMEM_MOVEABLE,  
    UINT nGrowBytes = 4096);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nAllocFlags*  
 Sinalizadores indicando como memória deve ser alocado. Consulte [GlobalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366574) para obter uma lista de valores de sinalizador válido.  
  
 `nGrowBytes`  
 O incremento de alocação de memória em bytes.  
  
##  <a name="detach"></a>CSharedFile::Detach  
 Chame essa função para fechar o arquivo de memória e desconectá-lo do bloco de memória.  
  
```  
HGLOBAL Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador do bloco de memória que contém o conteúdo do arquivo de memória.  
  
### <a name="remarks"></a>Comentários  
 Você poderá reabri-lo chamando [SetHandle](#sethandle), usando o identificador retornado por **desanexar**.  
  
##  <a name="sethandle"></a>CSharedFile::SetHandle  
 Chame essa função para anexar um bloco de memória global para o `CSharedFile` objeto.  
  
```  
void SetHandle(
    HGLOBAL hGlobalMemory,  
    BOOL bAllowGrow = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hGlobalMemory*  
 Identificador para a memória global a ser anexado ao `CSharedFile`.  
  
 `bAllowGrow`  
 Especifica se o bloco de memória pode crescer.  
  
### <a name="remarks"></a>Comentários  
 Se `bAllowGrow` é diferente de zero, o tamanho do bloco de memória é aumentado conforme necessário, por exemplo, se uma tentativa for feita para gravar bytes mais o arquivo que foram alocados para o bloco de memória.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CMemFile](../../mfc/reference/cmemfile-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CMemFile](../../mfc/reference/cmemfile-class.md)

