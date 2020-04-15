---
title: Classe CStdioFile
ms.date: 08/29/2019
f1_keywords:
- CStdioFile
- AFX/CStdioFile
- AFX/CStdioFile::CStdioFile
- AFX/CStdioFile::Open
- AFX/CStdioFile::ReadString
- AFX/CStdioFile::Seek
- AFX/CStdioFile::WriteString
- AFX/CStdioFile::m_pStream
helpviewer_keywords:
- CStdioFile [MFC], CStdioFile
- CStdioFile [MFC], Open
- CStdioFile [MFC], ReadString
- CStdioFile [MFC], Seek
- CStdioFile [MFC], WriteString
- CStdioFile [MFC], m_pStream
ms.assetid: 88c2274c-4f0e-4327-882a-557ba4b3ae15
ms.openlocfilehash: 80ee65aa339a38b3d8434bc4c7cb977e263f037b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366011"
---
# <a name="cstdiofile-class"></a>Classe CStdioFile

Representa um arquivo de fluxo de tempo de execução C, conforme aberto pelo fopen da função de tempo de [execução](../../c-runtime-library/reference/fopen-wfopen.md).

## <a name="syntax"></a>Sintaxe

```
class CStdioFile : public CFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CStdioFile::CStdioFile](#cstdiofile)|Constrói um `CStdioFile` objeto a partir de um caminho ou ponteiro de arquivo.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStdioFile::Aberto](#open)|Sobrecarregado. O open foi projetado `CStdioFile` para ser usado com o construtor padrão (Overrides [CFile::Open](../../mfc/reference/cfile-class.md#open)).|
|[CStdioFile::ReadString](#readstring)|Lê uma única linha de texto.|
|[CStdioFile::Buscar](#seek)|Posiciona o ponteiro de arquivo atual.|
|[CStdioFile::WriteString](#writestring)|Escreve uma única linha de texto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CStdioFile::m_pStream](#m_pstream)|Contém um ponteiro para um arquivo aberto.|

## <a name="remarks"></a>Comentários

Os arquivos de fluxo são protegidos e podem ser abertos no modo texto (o padrão) ou no modo binário.

O modo texto fornece processamento especial para pares de feeds de linha de retorno de transporte. Quando você escreve um caractere de feed de linha (newline) `CStdioFile` (0x0A) para um objeto de modo de texto, o par de bytes (0x0D, 0x0A) é enviado para o arquivo. Quando você lê, o par de bytes (0x0D, 0x0A) é traduzido para um único byte 0x0A.

As funções [CFile](../../mfc/reference/cfile-class.md) [Duplicate,](../../mfc/reference/cfile-class.md#duplicate) [LockRange](../../mfc/reference/cfile-class.md#lockrange)e [UnlockRange](../../mfc/reference/cfile-class.md#unlockrange) não são suportadas para `CStdioFile`.

Se você chamar essas `CStdioFile`funções em um , você receberá uma [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

Para obter mais `CStdioFile`informações sobre o uso, consulte os artigos [Arquivos em MFC](../../mfc/files-in-mfc.md) e [Tratamento de Arquivos](../../c-runtime-library/file-handling.md) na Referência da Biblioteca em Tempo de *Execução*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cfile](../../mfc/reference/cfile-class.md)

`CStdioFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="cstdiofilecstdiofile"></a><a name="cstdiofile"></a>CStdioFile::CStdioFile

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

*pOpenStream*<br/>
Especifica o ponteiro de arquivo retornado por uma chamada para o fopen da função de tempo de [execução C](../../c-runtime-library/reference/fopen-wfopen.md).

*lpszFileName*<br/>
Especifica uma string que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto.

*nOpenFlags*<br/>
Especifica opções para criação de arquivos, compartilhamento de arquivos e modos de acesso a arquivos. Você pode especificar várias opções **|** usando o operador bitwise OR ( ).

Uma opção de modo de acesso a arquivos é necessária; outros modos são opcionais. Consulte [CFile::CFile](../../mfc/reference/cfile-class.md#cfile) para obter uma lista de opções de modo e outros sinalizadores. Na versão 3.0 do MFC e posterior, são permitidas bandeiras de compartilhamento.

*Ptm*<br/>
Ponteiro para objeto CAtlTransactionManager.

### <a name="remarks"></a>Comentários

O construtor padrão não anexa um `CStdioFile` arquivo ao objeto. Ao usar este construtor, você `CStdioFile::Open` deve usar o método para `CStdioFile` abrir um arquivo e anexá-lo ao objeto.

O construtor de parâmetroúnico anexa um fluxo `CStdioFile` de arquivo aberto ao objeto. Os valores de ponteiro permitidos incluem os ponteiros de arquivo de entrada/saída predefinidos *stdin*, *stdout*ou *stderr*.

O construtor de dois parâmetros cria um `CStdioFile` objeto e abre o arquivo correspondente com o caminho dado.

Se você passar NULL para *pOpenStream* ou *lpszFileName,* o construtor lançará um `CInvalidArgException*`.

Se o arquivo não puder ser aberto ou `CFileException*`criado, o construtor lançará um .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#37](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_1.cpp)]

## <a name="cstdiofilem_pstream"></a><a name="m_pstream"></a>CStdioFile::m_pStream

O `m_pStream` membro de dados é o ponteiro para um arquivo `fopen`aberto, conforme retornado pela função C run-time .

```
FILE* m_pStream;
```

### <a name="remarks"></a>Comentários

É NULO se o arquivo nunca foi aberto ou foi fechado.

## <a name="cstdiofileopen"></a><a name="open"></a>CStdioFile::Aberto

Sobrecarregado. Open foi projetado para `CStdioFile` ser usado com o construtor padrão.

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

*lpszFileName*<br/>
Uma seqüência que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto.

*nOpenFlags*<br/>
Modo de compartilhamento e acesso. Especifica a ação a ser tomada ao abrir o arquivo. Você pode combinar opções usando o operador bitwise-OR (&#124;). Uma permissão de acesso e uma opção de compartilhamento são necessárias; os modosCriar e modeNoInherit são opcionais.

*pError*<br/>
Um ponteiro para um objeto de exceção de arquivo existente que receberá o status de uma operação com falha.

*Ptm*<br/>
Ponteiro para `CAtlTransactionManager` um objeto.

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cstdiofilereadstring"></a><a name="readstring"></a>CStdioFile::ReadString

Lê dados de texto em um buffer, até um limite de *caracteres nMax*-1, a partir do arquivo associado ao `CStdioFile` objeto.

```
virtual LPTSTR ReadString(
    LPTSTR lpsz,
    UINT nMax);

virtual BOOL ReadString(CString& rString);
```

### <a name="parameters"></a>Parâmetros

*Lpsz*<br/>
Especifica um ponteiro para um buffer fornecido pelo usuário que receberá uma seqüência de texto com término nulo.

*Nmax*<br/>
Especifica o número máximo de caracteres a serem lidos, sem contar o caractere nulo final.

*rString*<br/>
Uma referência `CString` a um objeto que conterá a seqüência quando a função retornar.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o buffer contendo os dados de texto. NULO se o fim do arquivo foi alcançado sem ler nenhum dado; ou se booleano, FALSO se o fim do arquivo foi alcançado sem ler nenhum dado.

### <a name="remarks"></a>Comentários

A leitura é interrompida pelo primeiro personagem newline. Se, nesse caso, menos caracteres *nMax*-1 foram lidos, um caractere newline será armazenado no buffer. Um caractere nulo ('\0') é anexado em ambos os casos.

[CFile::Read](../../mfc/reference/cfile-class.md#read) também está disponível para entrada no modo de texto, mas não termina em um par de feed supérse.

> [!NOTE]
> A `CString` versão desta função `'\n'` remove o se presente; a versão LPTSTR não.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#38](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_2.cpp)]

## <a name="cstdiofileseek"></a><a name="seek"></a>CStdioFile::Buscar

Reposiciona o ponteiro em um arquivo aberto anteriormente.

```
virtual ULONGLONG Seek(
    LONGLONG lOff,
    UINT nFrom);
```

### <a name="parameters"></a>Parâmetros

*Loff*<br/>
Número de bytes para mover o ponteiro.

*nFrom*<br/>
Modo de movimento do ponteiro. Deve ser um dos seguintes valores: 

- `CFile::begin`: Mova o ponteiro do arquivo *lOff* bytes para a frente desde o início do arquivo.

- `CFile::current`: Mova o ponteiro do arquivo *lOff* bytes da posição atual no arquivo.

- `CFile::end`: Mova o ponteiro do arquivo *lOff* bytes a partir do final do arquivo. Observe que *lOff* deve ser negativo para procurar no arquivo existente; valores positivos buscarão além do fim do arquivo.

### <a name="return-value"></a>Valor retornado

Se a posição solicitada `Seek` for legal, retorna o novo byte offset a partir do início do arquivo. Caso contrário, o valor de `CFileException` retorno é indefinido e um objeto é jogado.

### <a name="remarks"></a>Comentários

A `Seek` função permite acesso aleatório ao conteúdo de um arquivo movendo o ponteiro uma quantidade especificada, absolutamente ou relativamente. Nenhum dado é realmente lido durante a busca. Se a posição solicitada for maior do que o tamanho do arquivo, o comprimento do arquivo será estendido para essa posição, e nenhuma exceção será lançada.

Quando um arquivo é aberto, o ponteiro do arquivo é posicionado no offset 0, o início do arquivo.

Esta implementação `Seek` é baseada na função `fseek`Run-Time Library (CRT). Existem vários limites no `Seek` uso de fluxos abertos no modo texto. Para obter mais informações, consulte [fseek, _fseeki64](../../c-runtime-library/reference/fseek-fseeki64.md).

### <a name="example"></a>Exemplo

O exemplo a seguir `Seek` mostra como usar para mover o ponteiro 1000 bytes desde o início do `cfile` arquivo. Observe `Seek` que não lê dados, então você deve ligar para [CStdioFile::ReadString](#readstring) para ler dados.

[!code-cpp[NVC_MFCFiles#39](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_3.cpp)]

## <a name="cstdiofilewritestring"></a><a name="writestring"></a>CStdioFile::WriteString

Grava dados de um buffer para `CStdioFile` o arquivo associado ao objeto.

```
virtual void WriteString(LPCTSTR lpsz);
```

### <a name="parameters"></a>Parâmetros

*Lpsz*<br/>
Especifica um ponteiro para um buffer que contém uma seqüência de seqüência sumida.

### <a name="remarks"></a>Comentários

O caractere nulo `\0`de terminação ( ) não está escrito no arquivo. Este método escreve caracteres newline em *lpsz* para o arquivo como um par de feed de linha de retorno de transporte.

Se você quiser gravar dados que não sejam nulos `CStdioFile::Write` para um arquivo, use ou [CFile::Write](../../mfc/reference/cfile-class.md#write).

Este método `CInvalidArgException*` lança um se você especificar NULL para o parâmetro *lpsz.*

Este método `CFileException*` lança uma resposta a erros do sistema de arquivos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#40](../../atl-mfc-shared/reference/codesnippet/cpp/cstdiofile-class_4.cpp)]

## <a name="see-also"></a>Confira também

[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Arquivo::Duplicato](../../mfc/reference/cfile-class.md#duplicate)<br/>
[CFile::LockRange](../../mfc/reference/cfile-class.md#lockrange)<br/>
[CFile::UnlockRange](../../mfc/reference/cfile-class.md#unlockrange)<br/>
[Classe CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)
