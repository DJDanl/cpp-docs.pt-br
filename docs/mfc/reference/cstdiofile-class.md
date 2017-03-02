---
title: Classe CStdioFile | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CStdioFile
dev_langs:
- C++
helpviewer_keywords:
- CStdioFile class
- I/O [MFC], stream
- stream I/O
ms.assetid: 88c2274c-4f0e-4327-882a-557ba4b3ae15
caps.latest.revision: 22
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
ms.openlocfilehash: f3f036b409067676fdf12db9751cac1ea8025140
ms.lasthandoff: 02/25/2017

---
# <a name="cstdiofile-class"></a>Classe CStdioFile
Representa um arquivo de fluxo de tempo de execução C como aberto pela função de tempo de execução [fopen](../../c-runtime-library/reference/fopen-wfopen.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CStdioFile : public CFile  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStdioFile::CStdioFile](#cstdiofile)|Constrói uma `CStdioFile` objeto a partir de um ponteiro de arquivo ou caminho.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStdioFile::Open](#open)|Sobrecarregado. Abrir foi projetado para uso com o padrão `CStdioFile` construtor (substituições [CFile::Open](../../mfc/reference/cfile-class.md#open)).|  
|[CStdioFile::ReadString](#readstring)|Lê uma única linha de texto.|  
|[CStdioFile::Seek](#seek)|Posiciona o ponteiro do arquivo atual.|  
|[CStdioFile::WriteString](#writestring)|Grava uma única linha de texto.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStdioFile::m_pStream](#m_pstream)|Contém um ponteiro para um arquivo aberto.|  
  
## <a name="remarks"></a>Comentários  
 Arquivos de fluxo são armazenados em buffer e podem ser abertos no modo de texto (o padrão) ou modo binário.  
  
 Modo de texto fornece processamento especial para pares de retorno de avanço de linha de carro. Quando você escreve uma nova linha (0x0A) de caracteres para um modo de texto `CStdioFile` objeto, o par de bytes (0x0D, 0x0A) é enviada para o arquivo. Quando você lê, o par de bytes (0x0D, 0x0A) é convertido para um único byte 0x0A.  
  
 O [CFile](../../mfc/reference/cfile-class.md) funções [duplicar](../../mfc/reference/cfile-class.md#duplicate), [LockRange](../../mfc/reference/cfile-class.md#lockrange), e [UnlockRange](../../mfc/reference/cfile-class.md#unlockrange) não há suporte para `CStdioFile`.  
  
 Se você chamar essas funções em uma `CStdioFile`, você obterá um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).  
  
 Para obter mais informações sobre como usar o `CStdioFile`, consulte os artigos [arquivos no MFC](../../mfc/files-in-mfc.md) e [manuseio de arquivos](../../c-runtime-library/file-handling.md) no *referência da biblioteca de tempo de execução*.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 `CStdioFile`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h  
  
##  <a name="a-namecstdiofilea--cstdiofilecstdiofile"></a><a name="cstdiofile"></a>CStdioFile::CStdioFile  
 Constrói e inicializa um objeto `CStdioFile`.  
  
```  
CStdioFile();  
CStdioFile(CAtlTransactionManager* pTM);  
  CStdioFile(FILE* pOpenStream);

 
CStdioFile(
    LPCTSTR lpszFileName,  
    UINT nOpenFlags);

 
CStdioFile(
    LPCTSTR lpszFileName,
    UINT nOpenFlags,
    CAtlTransactionManager* pTM);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pOpenStream`  
 Especifica o ponteiro de arquivo retornado por uma chamada para a função de tempo de execução C [fopen](../../c-runtime-library/reference/fopen-wfopen.md).  
  
 `lpszFileName`  
 Especifica uma cadeia de caracteres que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto.  
  
 `nOpenFlags`  
 Especifica opções para criação de arquivos, compartilhamento de arquivos e modos de acesso de arquivo. Você pode especificar várias opções usando o OR bit a bit ( `|`) operador.  
  
 Uma opção de modo de acesso de arquivo é necessária; outros modos são opcionais. Consulte [CFile::CFile](../../mfc/reference/cfile-class.md#cfile) para obter uma lista de opções de modo e outros sinalizadores. MFC versão 3.0 e posterior, sinalizadores de compartilhamento são permitidas.  
  
 `pTM`  
 Ponteiro para objeto CAtlTransactionManager.  
  
### <a name="remarks"></a>Comentários  
 O construtor padrão não anexar um arquivo para o `CStdioFile` objeto. Ao usar esse construtor, você deve usar o `CStdioFile::Open` método para abrir um arquivo e anexá-lo a `CStdioFile` objeto.  
  
 O único parâmetro construtor anexa um fluxo de arquivos abertos para o `CStdioFile` objeto. Permitidos valores de ponteiro incluem os ponteiros de arquivo de entrada/saída predefinido `stdin`, `stdout`, ou `stderr`.  
  
 O construtor de dois parâmetros cria um `CStdioFile` object e abre o arquivo correspondente com o caminho fornecido.  
  
 Se você passar `NULL` para um `pOpenStream` ou `lpszFileName`, o construtor lançará um `CInvalidArgException*`.  
  
 Se o arquivo não pode ser aberto ou criado, o construtor lançará um `CFileException*`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCFiles&#37;](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_1.cpp)]  
  
##  <a name="a-namempstreama--cstdiofilempstream"></a><a name="m_pstream"></a>CStdioFile::m_pStream  
 O `m_pStream` membro de dados é o ponteiro para um arquivo aberto como retornado pela função de tempo de execução C `fopen`.  
  
```  
FILE* m_pStream;  
```  
  
### <a name="remarks"></a>Comentários  
 É **nulo** se o arquivo nunca foi aberto ou foi fechado.  
  
##  <a name="a-nameopena--cstdiofileopen"></a><a name="open"></a>CStdioFile::Open  
 Sobrecarregado. Abrir foi projetado para uso com o padrão `CStdioFile` construtor.  
  
```  
virtual BOOL Open(
    LPCTSTR lpszFileName,  
    UINT nOpenFlags,  
    CFileException* pError = NULL);

 
virtual BOOL Open(
    LPCTSTR lpszFileName,  
    UINT nOpenFlags,  
    CAtlTransactionManager* pTM,  
    CFileException* pError = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFileName`  
 Uma cadeia de caracteres que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto.  
  
 `nOpenFlags`  
 Modo de compartilhamento e acesso. Especifica a ação a ser tomada ao abrir o arquivo. Você pode combinar as opções usando o operador OR bit a bit (|). Permissão de acesso de um e um compartilhamento de opção são necessários; os modos de modeCreate e modeNoInherit são opcionais.  
  
 `pError`  
 Um ponteiro para um objeto de exceção de arquivo existente que receberá o status de uma operação com falha.  
  
 `pTM`  
 Ponteiro para uma `CAtlTransactionManager` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` caso bem-sucedido; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namereadstringa--cstdiofilereadstring"></a><a name="readstring"></a>CStdioFile::ReadString  
 Lê dados de texto em um buffer, até o limite de `nMax`caracteres –&1;, do arquivo associado a `CStdioFile` objeto.  
  
```  
virtual LPTSTR ReadString(
    LPTSTR lpsz,  
    UINT nMax);  
  
virtual BOOL ReadString(CString& rString);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpsz`  
 Especifica um ponteiro para um buffer fornecido pelo usuário que receberá uma cadeia de caracteres de texto terminada em nulo.  
  
 `nMax`  
 Especifica o número máximo de caracteres a serem lidos, sem contar o caractere de terminação nula.  
  
 `rString`  
 Uma referência a um `CString` objeto que contém a cadeia de caracteres quando a função retorna.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o buffer que contém os dados de texto. **NULO** se o fim do arquivo foi atingido sem ler todos os dados; ou se boolean, **FALSE** se o fim do arquivo foi atingido sem ler todos os dados.  
  
### <a name="remarks"></a>Comentários  
 Leitura for interrompida, o primeiro caractere de nova linha. Se, nesse caso, menos de `nMax`–&1; caracteres tenham sido lidos, um caractere de nova linha é armazenado em buffer. Um caractere nulo ('\0') é acrescentado em ambos os casos.  
  
 [CFile::Read](../../mfc/reference/cfile-class.md#read) também está disponível para entrada de modo de texto, mas ele não encerra em um par de avanço de linha retorno de carro.  
  
> [!NOTE]
>  O `CString` versão dessa função remove o `'\n'` se estiver presente; o `LPTSTR` versão não.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCFiles&38;](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_2.cpp)]  
  
##  <a name="a-nameseeka--cstdiofileseek"></a><a name="seek"></a>CStdioFile::Seek  
 Reposiciona o ponteiro em um arquivo aberto anteriormente.  
  
```  
virtual ULONGLONG Seek(
    LONGLONG lOff,  
    UINT nFrom);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lOff`  
 Número de bytes para mover o ponteiro.  
  
 `nFrom`  
 Modo de movimentação do ponteiro. Deve ser um dos seguintes valores:  
  
- `CFile::begin`: Mover o ponteiro do arquivo `lOff` bytes encaminham desde o início do arquivo.  
  
- `CFile::current`: Mover o ponteiro do arquivo `lOff` bytes a partir da posição atual no arquivo.  
  
- `CFile::end`: Mover o ponteiro do arquivo `lOff` bytes do final do arquivo. Observe que `lOff` deve ser negativo para busca no existente de arquivos; positivo valores buscará após o final do arquivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a posição solicitada é legal, `Seek` retorna o deslocamento de byte novo desde o início do arquivo. Caso contrário, o valor retornado é indefinido e um `CFileException` objeto é lançado.  
  
### <a name="remarks"></a>Comentários  
 O `Seek` função permite acesso aleatório ao conteúdo do arquivo, movendo o ponteiro um valor especificado, absolutamente ou relativamente. Na verdade, nenhum dado será lido durante a busca. Se a posição for maior que o tamanho do arquivo, o comprimento do arquivo será estendido para essa posição e nenhuma exceção será lançada.  
  
 Quando um arquivo é aberto, o ponteiro é posicionado no deslocamento 0, o início do arquivo.  
  
 Essa implementação do `Seek` é baseado na função de biblioteca de tempo de execução (CRT) `fseek`. Há vários limites de uso do `Seek` em fluxos abertos no modo de texto. Para obter mais informações, consulte [fseek, fseeki64](../../c-runtime-library/reference/fseek-fseeki64.md).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como usar `Seek` para mover o ponteiro 1.000 bytes do início do `cfile` arquivo. Observe que `Seek` não ler dados, então você deve chamar subsequentemente [CStdioFile::ReadString](#readstring) para ler dados.  
  
 [!code-cpp[NVC_MFCFiles&#39;](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_3.cpp)]  
  
##  <a name="a-namewritestringa--cstdiofilewritestring"></a><a name="writestring"></a>CStdioFile::WriteString  
 Grava dados de um buffer para o arquivo associado a `CStdioFile` objeto.  
  
```  
virtual void WriteString(LPCTSTR lpsz);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpsz`  
 Especifica um ponteiro para um buffer que contém uma cadeia de caracteres terminada em nulo.  
  
### <a name="remarks"></a>Comentários  
 O caractere nulo de terminação ( `\0`) não é gravado no arquivo. Esse método grava caracteres de nova linha `lpsz` para o arquivo como um par de avanço de linha/retorno de carro.  
  
 Se você quiser gravar dados que não é finalizada com null em um arquivo, use `CStdioFile::Write` ou [CFile::Write](../../mfc/reference/cfile-class.md#write).  
  
 Este método lança um `CInvalidArgException*` se você especificar `NULL` para o `lpsz` parâmetro.  
  
 Este método lança um `CFileException*` em resposta a erros do sistema de arquivos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[40 NVC_MFCFiles](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_4.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe CFile](../../mfc/reference/cfile-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFile](../../mfc/reference/cfile-class.md)   
 [CFile::Duplicate](../../mfc/reference/cfile-class.md#duplicate)   
 [CFile::LockRange](../../mfc/reference/cfile-class.md#lockrange)   
 [CFile::UnlockRange](../../mfc/reference/cfile-class.md#unlockrange)   
 [Classe CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)

