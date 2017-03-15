---
title: Classe CMemFile | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMemFile
dev_langs:
- C++
helpviewer_keywords:
- memory files
- CMemFile class
- temporary files, memory files
ms.assetid: 20e86515-e465-4f73-b2ea-e49789d63165
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 9851e050b05ac129e5e498c7ea99dfedddc79e54
ms.lasthandoff: 02/25/2017

---
# <a name="cmemfile-class"></a>Classe CMemFile
O [CFile](../../mfc/reference/cfile-class.md)-derivada da classe que oferece suporte a arquivos de memória.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMemFile : public CFile  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMemFile::CMemFile](#cmemfile)|Constrói um objeto de arquivo de memória.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMemFile::Attach](#attach)|Anexa um bloco de memória para `CMemFile`.|  
|[CMemFile::Detach](#detach)|Desanexa o bloco de memória de `CMemFile` e retorna um ponteiro para o bloco de memória desanexado.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMemFile::Alloc](#alloc)|Substituição para modificar o comportamento de alocação de memória.|  
|[CMemFile::Free](#free)|Substituição para modificar o comportamento de desalocação de memória.|  
|[CMemFile::GrowFile](#growfile)|Substituição para modificar o comportamento ao cultivar um arquivo.|  
|[CMemFile::Memcpy](#memcpy)|Substitua para modificar o comportamento de cópia de memória ao ler e gravar arquivos.|  
|[CMemFile::Realloc](#realloc)|Substituição para modificar o comportamento de realocação de memória.|  
  
## <a name="remarks"></a>Comentários  
 Esses arquivos de memória se comportam como arquivos do disco, exceto que o arquivo é armazenado na RAM, e não no disco. Um arquivo de memória é útil para armazenamento temporário rápida ou transferir os bytes brutos ou serializado objetos entre processos independentes.  
  
 `CMemFile`objetos podem alocar automaticamente sua própria memória ou você pode anexar seu próprio bloco de memória para o `CMemFile` chamando [Attach](#attach). Em ambos os casos, a memória para expandir o arquivo de memória automaticamente é alocada em `nGrowBytes`-em incrementos de tamanho se `nGrowBytes` não for zero.  
  
 O bloco de memória será excluído automaticamente após a destruição do `CMemFile` objeto se a memória foi alocada originalmente pelo `CMemFile` objeto; caso contrário, você é responsável por desalocar a memória anexado ao objeto.  
  
 Você pode acessar o bloco de memória usando o ponteiro fornecido ao desanexar do `CMemFile` chamando [desanexar](#detach).  
  
 O uso mais comum de `CMemFile` é criar um `CMemFile` de objeto e usá-lo chamando [CFile](../../mfc/reference/cfile-class.md) funções de membro. Observe que criar um `CMemFile` abre automaticamente: você não chamar [CFile::Open](../../mfc/reference/cfile-class.md#open), que é usado somente para arquivos de disco. Porque `CMemFile` não usa um arquivo de disco, o membro de dados `CFile::m_hFile` não é usado.  
  
 O `CFile` funções de membro [duplicar](../../mfc/reference/cfile-class.md#duplicate), [LockRange](../../mfc/reference/cfile-class.md#lockrange), e [UnlockRange](../../mfc/reference/cfile-class.md#unlockrange) não são implementadas para `CMemFile`. Se você chamar essas funções em uma `CMemFile` do objeto, você obterá um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).  
  
 `CMemFile`usa as funções de biblioteca de tempo de execução [malloc](../../c-runtime-library/reference/malloc.md), [realloc](../../c-runtime-library/reference/realloc.md), e [livre](../../c-runtime-library/reference/free.md) para alocar, realocar e desalocar memória; e o intrínseco [memcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md) bloco cópia memória ao ler e gravar. Se desejar alterar esse comportamento ou o comportamento quando `CMemFile` aumenta um arquivo derivar sua própria classe de `CMemFile` e substituir as funções apropriadas.  
  
 Para obter mais informações sobre `CMemFile`, consulte os artigos [arquivos no MFC](../../mfc/files-in-mfc.md) e [gerenciamento de memória (MFC)](../../mfc/memory-management.md) e [manuseio de arquivos](../../c-runtime-library/file-handling.md) no *referência da biblioteca de tempo de execução*.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 `CMemFile`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h  
  
##  <a name="a-namealloca--cmemfilealloc"></a><a name="alloc"></a>CMemFile::Alloc  
 Essa função é chamada pelo `CMemFile` funções de membro.  
  
```  
virtual BYTE* Alloc(SIZE_T nBytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBytes`  
 Número de bytes de memória a ser alocada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o bloco de memória que foi alocado, ou **nulo** se a alocação de falha.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para implementar a alocação de memória personalizados. Se você substituir essa função, você provavelmente desejará substituir [livre](#free) e [Realloc](#realloc) também.  
  
 A implementação padrão usa a função de biblioteca de tempo de execução [malloc](../../c-runtime-library/reference/malloc.md) ao alocar memória.  
  
##  <a name="a-nameattacha--cmemfileattach"></a><a name="attach"></a>CMemFile::Attach  
 Chame essa função para anexar um bloco de memória para `CMemFile`.  
  
```  
void Attach(
    BYTE* lpBuffer,  
    UINT nBufferSize,  
    UINT nGrowBytes = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpBuffer`  
 Ponteiro para o buffer a ser anexado à `CMemFile`.  
  
 `nBufferSize`  
 Um inteiro que especifica o tamanho do buffer em bytes.  
  
 `nGrowBytes`  
 O incremento de alocação de memória em bytes.  
  
### <a name="remarks"></a>Comentários  
 Isso faz com que `CMemFile` para usar o bloco de memória que o arquivo de memória.  
  
 Se `nGrowBytes` é 0, `CMemFile` definirá o tamanho de arquivo `nBufferSize`. Isso significa que os dados na memória bloqueada antes que ele foi anexado ao `CMemFile` será usado como o arquivo. Arquivos de memória criados dessa maneira não podem ser personalizados.  
  
 Uma vez que o arquivo não pode ser expandido, tenha cuidado para não causar `CMemFile` para tentar aumentar o arquivo. Por exemplo, não chame o `CMemFile` substituições de [CFile:Write](../../mfc/reference/cfile-class.md#write) para gravação após o final ou não chamar [CFile:SetLength](../../mfc/reference/cfile-class.md#setlength) com um tamanho maior que `nBufferSize`.  
  
 Se `nGrowBytes` é maior que 0, `CMemFile` irá ignorar o conteúdo do bloco de memória anexado. Você precisará escrever o conteúdo do arquivo de memória de trabalho usando o `CMemFile` substituir de `CFile::Write`. Se você tentar gravar após o final do arquivo ou o tamanho do arquivo chamando o `CMemFile` substituir de `CFile::SetLength`, `CMemFile` aumentará a alocação de memória em incrementos de `nGrowBytes`. Aumentando a alocação de memória falhará se o bloco de memória que você passar para **Attach** não foi alocado com um método compatível com [alocação](#alloc). Para ser compatível com a implementação padrão de `Alloc`, você deve alocar a memória com a função de biblioteca de tempo de execução [malloc](../../c-runtime-library/reference/malloc.md) ou [calloc](../../c-runtime-library/reference/calloc.md).  
  
##  <a name="a-namecmemfilea--cmemfilecmemfile"></a><a name="cmemfile"></a>CMemFile::CMemFile  
 A primeira sobrecarga abre um arquivo de memória vazia.  
  
```  
CMemFile(UINT nGrowBytes = 1024);

 
CMemFile(
    BYTE* lpBuffer,  
    UINT nBufferSize,  
    UINT nGrowBytes = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nGrowBytes`  
 O incremento de alocação de memória em bytes.  
  
 *lpBuffe*r  
 Ponteiro para um buffer que recebe informações de tamanho `nBufferSize`.  
  
 `nBufferSize`  
 Um inteiro que especifica o tamanho do buffer de arquivo, em bytes.  
  
### <a name="remarks"></a>Comentários  
 Observe que o arquivo seja aberto pelo construtor e que você não deve chamar [CFile::Open](../../mfc/reference/cfile-class.md#open).  
  
 A segunda sobrecarga age como se você usou o primeiro construtor e chamado imediatamente o mesmo [Attach](#attach) com os mesmos parâmetros. Consulte **Attach** para obter detalhes.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCFiles&#36;](../../atl-mfc-shared/reference/codesnippet/cpp/cmemfile-class_1.cpp)]  
  
##  <a name="a-namedetacha--cmemfiledetach"></a><a name="detach"></a>CMemFile::Detach  
 Chame essa função para obter um ponteiro para o bloco de memória que está sendo usado por `CMemFile`.  
  
```  
BYTE* Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o bloco de memória que contém o conteúdo do arquivo de memória.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função também fecha o `CMemFile`. Você pode anexar novamente o bloco de memória para `CMemFile` chamando [Attach](#attach). Se você deseja anexar o arquivo e use os dados, você deve chamar [CFile::GetLength](../../mfc/reference/cfile-class.md#getlength) para obter o tamanho do arquivo antes de chamar **desanexar**. Observe que, se você anexar um bloco de memória para `CMemFile` para que você possa usar seus dados ( `nGrowBytes` = = 0), em seguida, você não poderá aumentar o arquivo de memória.  
  
##  <a name="a-namefreea--cmemfilefree"></a><a name="free"></a>CMemFile::Free  
 Essa função é chamada pelo `CMemFile` funções de membro.  
  
```  
virtual void Free(BYTE* lpMem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMem`  
 Ponteiro para a memória ser desalocada *.*  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para implementar a desalocação de memória personalizados. Se você substituir essa função, você provavelmente desejará substituir [alocação](#alloc) e [Realloc](#realloc) também.  
  
##  <a name="a-namegrowfilea--cmemfilegrowfile"></a><a name="growfile"></a>CMemFile::GrowFile  
 Essa função é chamada por vários do `CMemFile` funções de membro.  
  
```  
virtual void GrowFile(SIZE_T dwNewLen);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwNewLen`  
 Novo tamanho do arquivo de memória.  
  
### <a name="remarks"></a>Comentários  
 Você pode substituí-la se você desejar alterar como `CMemFile` aumenta seu arquivo. As chamadas de implementação padrão [Realloc](#realloc) cresça um bloco existente (ou [alocação](#alloc) para criar um bloco de memória), alocação de memória em múltiplos do `nGrowBytes` valor especificado no construtor ou [Attach](#attach) chamar.  
  
##  <a name="a-namememcpya--cmemfilememcpy"></a><a name="memcpy"></a>CMemFile::Memcpy  
 Essa função é chamada o `CMemFile` substituições de [CFile::Read](../../mfc/reference/cfile-class.md#read) e [CFile::Write](../../mfc/reference/cfile-class.md#write) para transferir dados de e para o arquivo de memória.  
  
```  
virtual BYTE* Memcpy(
    BYTE* lpMemTarget,  
    const BYTE* lpMemSource,  
    SIZE_T nBytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMemTarget`  
 Ponteiro para o bloco de memória na qual a memória de origem será copiada.  
  
 `lpMemSource`  
 Ponteiro para o bloco de memória de origem.  
  
 `nBytes`  
 Número de bytes a serem copiados.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cópia de `lpMemTarget`.  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função se você quiser alterar a maneira que `CMemFile` essas cópias de memória.  
  
##  <a name="a-namerealloca--cmemfilerealloc"></a><a name="realloc"></a>CMemFile::Realloc  
 Essa função é chamada pelo `CMemFile` funções de membro.  
  
```  
virtual BYTE* Realloc(
    BYTE* lpMem,  
    SIZE_T nBytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMem`  
 Um ponteiro para o bloco de memória sejam realocados.  
  
 `nBytes`  
 Novo tamanho para o bloco de memória.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o bloco de memória que foi realocado (e possivelmente movido), ou **nulo** se a realocação de falha.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para implementar a realocação de memória personalizados. Se você substituir essa função, você provavelmente desejará substituir [alocação](#alloc) e [livre](#free) também.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CFile](../../mfc/reference/cfile-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




