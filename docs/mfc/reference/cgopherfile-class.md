---
title: Classe CGopherFile | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CGopherFile
- AFXINET/CGopherFile
- AFXINET/CGopherFile::CGopherFile
dev_langs:
- C++
helpviewer_keywords:
- gopher protocol files
- Internet, gopher
- CGopherFile class
ms.assetid: 3ca9898f-8cdb-4495-bbde-46d40100feda
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 40c1e385d0f58095c2aa79cc23168fc00f48ed9b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cgopherfile-class"></a>Classe CGopherFile
Fornece a funcionalidade para localizar e ler arquivos em um servidor gopher.  
  
> [!NOTE]
>  As classes `CGopherConnection`, `CGopherFile`, `CGopherFileFind`, `CGopherLocator` e seus membros tenham sido substituídos porque eles não funcionam na plataforma Windows XP, mas eles continuarão a funcionar em plataformas anteriores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CGopherFile : public CInternetFile  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGopherFile::CGopherFile](#cgopherfile)|Constrói um objeto `CGopherFile`.|  
  
## <a name="remarks"></a>Comentários  
 O serviço gopher não permitir que os usuários gravar dados em um arquivo gopher porque esse serviço funciona principalmente como uma interface orientado por menus para localizar informações. O `CGopherFile` funções de membro **gravar**, `WriteString`, e `Flush` não são implementadas para `CGopherFile`. Chamar essas funções em uma `CGopherFile` objeto retorna um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).  
  
 Para saber mais sobre como `CGopherFile` funciona com as outras classes do MFC Internet, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 [CStdioFile](../../mfc/reference/cstdiofile-class.md)  
  
 [CInternetFile](../../mfc/reference/cinternetfile-class.md)  
  
 `CGopherFile`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxinet.h  
  
##  <a name="cgopherfile"></a>CGopherFile::CGopherFile  
 Essa função de membro é chamada para construir uma `CGopherFile` objeto.  
  
```  
CGopherFile(
    HINTERNET hFile,  
    CGopherLocator& refLocator,  
    CGopherConnection* pConnection);

 
CGopherFile(
    HINTERNET hFile,  
    HINTERNET hSession,  
    LPCTSTR pstrLocator,  
    DWORD dwLocLen,  
    DWORD_PTR dwContext);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hFile`  
 Um identificador para um `HINTERNET` arquivo.  
  
 `refLocator`  
 Uma referência a um [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) objeto.  
  
 `pConnection`  
 Um ponteiro para um [CGopherConnection](../../mfc/reference/cgopherconnection-class.md) objeto.  
  
 `hSession`  
 Um identificador para a sessão atual da Internet.  
  
 `pstrLocator`  
 Um ponteiro para uma cadeia de caracteres usada para localizar o servidor gopher. Consulte [sessões Gopher](https://msdn.microsoft.com/library/24wz8xze.aspx) para obter mais informações sobre localizadores gopher.  
  
 *dwLocLen*  
 Um DWORD que contém o número de bytes em `pstrLocator`.  
  
 `dwContext`  
 Um ponteiro para o identificador de contexto do arquivo que está sendo aberto.  
  
### <a name="remarks"></a>Comentários  
 Você precisa de uma `CGopherFile` objeto para ler de um arquivo durante uma sessão de Internet gopher.  
  
 Você nunca cria um `CGopherFile` diretamente do objeto. Em vez disso, chame [CGopherConnection::OpenFile](../../mfc/reference/cgopherconnection-class.md#openfile) para abrir um arquivo em um servidor gopher.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)   
 [Classe CGopherLocator](../../mfc/reference/cgopherlocator-class.md)   
 [Classe CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)   
 [Classe CGopherConnection](../../mfc/reference/cgopherconnection-class.md)

