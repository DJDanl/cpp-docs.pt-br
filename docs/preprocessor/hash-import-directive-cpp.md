---
title: '#Diretiva import (C++)'
ms.date: 08/29/2019
f1_keywords:
- '#import'
helpviewer_keywords:
- .tlh files
- '#import directive'
- import directive (#import)
- tlh files
- tlbid switch
- preprocessor, directives
- COM, type library header file
ms.assetid: 787d1112-e543-40d7-ab15-a63d43f4030a
ms.openlocfilehash: afd05e7380ec3838fe9763be23ccfae338adb4fb
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220266"
---
# <a name="import-directive-c"></a>Diretiva de #importC++()

**C++Determinados**

Usada para incorporar informações de uma biblioteca de tipos. O conteúdo da biblioteca de tipos é convertido em classes do C++, a maioria descrevendo as interfaces COM.

## <a name="syntax"></a>Sintaxe

> **#import** *atributos*de " \[*filename*"] \
> **#import**> atributos de nome dearquivo\[] \<

### <a name="parameters"></a>Parâmetros

*nome do arquivo*\
Especifica a biblioteca de tipos a ser importada. O *nome do arquivo* pode ser um dos seguintes tipos:

- O nome de um arquivo que contém uma biblioteca de tipos, como um arquivo .olb, .tlb ou .dll. A palavra- `file:`chave,, pode preceder cada nome de arquivo.

- O progid de um controle na biblioteca de tipos. A palavra- `progid:`chave,, pode preceder cada ProgID. Por exemplo:

    ```cpp
    #import "progid:my.prog.id.1.5"
    ```

   Para obter mais informações sobre ProgIDs, consulte [especificando a ID de localização e o número de versão](#_predir_the_23import_directive_specifyingthelocalizationidandversionnumber).

   Quando você usa um compilador cruzado de 32 bits em um sistema operacional de 64 bits, o compilador só pode ler o hive do registro de 32 bits. Pode ser conveniente usar o compilador de 64 bits nativo para criar e registrar uma biblioteca de tipos de 64 bits.

- A ID da biblioteca de tipos. A palavra- `libid:`chave,, pode preceder cada ID de biblioteca. Por exemplo:

    ```cpp
    #import "libid:12341234-1234-1234-1234-123412341234" version("4.0") lcid("9")
    ```

   Se você não especificar `version` ou `lcid`, as [regras](#_predir_the_23import_directive_specifyingthelocalizationidandversionnumber) aplicadas a `progid:` também serão aplicadas a `libid:`.

- Um arquivo executável (.exe).

- Um arquivo de biblioteca (. dll) que contém um recurso de biblioteca de tipos (como um. ocx).

- Um documento composto que contém uma biblioteca de tipos.

- Qualquer outro formato de arquivo que possa ser compreendido pela API LoadTypeLib.

*atributos*\
Um ou mais [atributos de #import](#_predir_the_23import_directive_import_attributes). Separe os atributos com espaços ou vírgulas. Por exemplo:

```cpp
#import "..\drawctl\drawctl.tlb" no_namespace, raw_interfaces_only
```

\-ou-

```cpp
#import "..\drawctl\drawctl.tlb" no_namespace raw_interfaces_only
```

## <a name="remarks"></a>Comentários

### <a name="_predir_the_23import_directive_searchorderforfilename"></a>Ordem de pesquisa do nome do arquivo

o *nome de arquivo* é opcionalmente precedido por uma especificação de diretório. O nome do arquivo deve nomear um arquivo existente. A diferença entre os dois formatos de sintaxe é a ordem em que o pré-processador procura os arquivos de biblioteca de tipos quando o caminho é especificado de forma incompleta.

|Formato de sintaxe|Ação|
|-----------------|------------|
|Forma entre aspas|Instrui o pré-processador a procurar os arquivos de biblioteca de tipos primeiro no diretório do arquivo que contém a instrução **#import** e, em seguida, nos diretórios de quaisquer arquivos que incluam (`#include`) esse arquivo. Em seguida, o pré-processador pesquisa ao longo dos caminhos mostrados abaixo.|
|Forma de colchete angular|Instrui o pré-processador a procurar arquivos de biblioteca de tipos ao longo dos seguintes caminhos:<br /><br /> 1.  A `PATH` lista de caminhos da variável de ambiente<br />2.  A `LIB` lista de caminhos da variável de ambiente<br />3.  O caminho especificado pela opção de compilador [/i](../build/reference/i-additional-include-directories.md) , exceto que o compilador está procurando uma biblioteca de tipos que foi referenciada de outra biblioteca de tipos com o atributo [no_registry](../preprocessor/no-registry.md) .|

### <a name="_predir_the_23import_directive_specifyingthelocalizationidandversionnumber"></a>Especifique a ID de localização e o número de versão

Ao especificar um progid, você também pode especificar a ID de localização e o número de versão do progid. Por exemplo:

```cpp
#import "progid:my.prog.id" lcid("0") version("4.0)
```

Se você não especificar uma ID de localização, um ProgID será escolhido de acordo com as seguintes regras:

- Se houver apenas uma ID de localização, ela será usada.

- Se houver mais de uma ID de localização, a primeira com o número de versão 0, 9 ou 409 será usada.

- Se houver mais de uma ID de localização e nenhuma delas for 0, 9 ou 409, a última será usada.

- Se você não especificar um número de versão, a versão mais recente será usada.

###  <a name="_predir_the_23import_directive_header_files_created_by_import"></a>Arquivos de cabeçalho criados por importação

**#import** cria dois arquivos de cabeçalho que reconstróim o conteúdo da C++ biblioteca de tipos no código-fonte. O arquivo de cabeçalho principal é semelhante ao produzido pelo compilador de linguagem IDL da Microsoft (MIDL), mas com código e dados gerados pelo compilador adicionais. O [arquivo de cabeçalho principal](#_predir_the_primary_type_library_header_file) tem o mesmo nome base que a biblioteca de tipos, mais um. Extensão TLH. O arquivo de cabeçalho secundário tem o mesmo nome base que a biblioteca de tipos, com a extensão .TLI. Ele contém as implementações para funções de membro geradas pelo compilador e está incluído (`#include`) no arquivo de cabeçalho principal.

Se estiver importando uma propriedade `byref` dispinterface que usa parâmetros, **#import** não gerará uma instrução [_ declspec (Property)](../cpp/property-cpp.md) para a função.

Ambos os arquivos de cabeçalho são colocados no diretório de saída especificado pela opção [/FO (nome do arquivo de objeto)](../build/reference/fo-object-file-name.md) . Em seguida, eles são lidos e compilados pelo compilador como se o arquivo de cabeçalho principal `#include` fosse nomeado por uma diretiva.

As seguintes otimizações de compilador vêm com a diretiva **#import** :

- O arquivo de cabeçalho, quando é criado, recebe o mesmo carimbo de data/hora que a biblioteca de tipos.

- Quando **#import** é processado, o compilador verifica primeiro se o cabeçalho existe e está atualizado. Em caso afirmativo, ele não precisa ser recriado.

A diretiva **#import** também participa da recompilação mínima e pode ser colocada em um arquivo de cabeçalho pré-compilado.  Para obter mais informações, consulte [criando arquivos de cabeçalho pré-compilados](../build/creating-precompiled-header-files.md).

### <a name="_predir_the_primary_type_library_header_file"></a>Arquivo de cabeçalho da biblioteca de tipos primário

O arquivo de cabeçalho principal da biblioteca de tipos consiste em sete seções:

- Texto clichê do título: Consiste em comentários, `#include` instrução para COMDEF. H (que define algumas macros padrão usadas no cabeçalho) e outras informações de configuração diversas.

- Referências diretas e TYPEDEFs: Consiste em declarações de estrutura, `struct IMyInterface` como e TYPEDEFs.

- Declarações de ponteiro inteligente: A classe `_com_ptr_t` de modelo é um ponteiro inteligente. Ele encapsula ponteiros de interface e elimina a necessidade de chamar `AddRef`, `Release`e `QueryInterface` funções. Ele também oculta a `CoCreateInstance` chamada ao criar um novo objeto com. Esta seção usa a instrução `_COM_SMARTPTR_TYPEDEF` macro para estabelecer TYPEDEFs de interfaces com como especializações de modelo da classe de modelo [_com_ptr_t](../cpp/com-ptr-t-class.md) . Por exemplo, para interface `IMyInterface`, a. O arquivo TLH conterá:

    ```TLH
    _COM_SMARTPTR_TYPEDEF(IMyInterface, __uuidof(IMyInterface));
    ```

   que o compilador expande para:

    ```cpp
    typedef _com_ptr_t<_com_IIID<IMyInterface, __uuidof(IMyInterface)> > IMyInterfacePtr;
    ```

   O tipo `IMyInterfacePtr` pode então ser usado no lugar do ponteiro de interface bruto `IMyInterface*`. Consequentemente, não há necessidade de chamar as várias `IUnknown` funções de membro

- Declarações TypeInfo: Consiste principalmente em definições de classe e outros itens expondo os itens de TypeInfo individuais `ITypeLib:GetTypeInfo`retornados pelo. Nesta seção, cada typeinfo da biblioteca de tipos é refletido no cabeçalho em um formato que depende das informações de `TYPEKIND`.

- Definição de GUID de estilo antigo opcional: Contém inicializações das constantes GUID nomeadas. Esses nomes têm o formato `CLSID_CoClass` e `IID_Interface`, semelhante àqueles gerados pelo compilador MIDL.

- Instrução `#include` para o cabeçalho secundário da biblioteca de tipos.

- Texto clichê do rodapé: Inclui `#pragma pack(pop)`atualmente.

Todas as seções, exceto a seção clichê de título e de rodapé, são colocadas em um namespace com seu nome especificado `library` pela instrução no arquivo IDL original. Você pode usar os nomes do cabeçalho da biblioteca de tipos por uma qualificação explícita usando o nome do namespace. Ou, você pode incluir a seguinte instrução:

```cpp
using namespace MyLib;
```

imediatamente após a instrução de **#import** no código-fonte.

O namespace pode ser suprimido usando o atributo [no_namespace](no-namespace.md)) da diretiva **#import** . No entanto, suprimir o namespace pode resultar em colisões de nomes. O namespace também pode ser renomeado pelo atributo [rename_namespace](rename-namespace.md) .

O compilador fornece o caminho completo para qualquer dependência de biblioteca de tipos exigida pela biblioteca de tipos que está processando no momento. O caminho é escrito, na forma de comentários, no cabeçalho da biblioteca de tipos (.TLH) gerado pelo compilador para cada biblioteca de tipos processada.

Se uma biblioteca de tipos incluir referências a tipos definidos em outras bibliotecas, o arquivo .TLH incluirá comentários do seguinte tipo:

```TLH
//
// Cross-referenced type libraries:
//
//  #import "c:\path\typelib0.tlb"
//
```

O nome de arquivo real no comentário de **#import** é o caminho completo da biblioteca de tipos com referência cruzada, conforme armazenado no registro. Se você encontrar erros causados por definições de tipo ausentes, verifique os comentários no cabeçalho do. TLH para ver quais bibliotecas de tipos dependentes talvez precisem ser importadas primeiro. Erros prováveis são erros de sintaxe (por exemplo, C2143, C2146, C2321), C2501 (especificadores de declarações ausentes) ou C2433 ("embutido" não permitido na declaração de dados) ao compilar o arquivo .TLI.

Para resolver erros de dependência, determine qual dos comentários de dependência não são fornecidos de outra forma para os cabeçalhos do sistema e, em seguida, forneça uma diretiva de **#import** em algum momento antes da diretiva **#import** da biblioteca de tipos dependente.

### <a name="_predir_the_23import_directive_import_attributes"></a>atributos de #import

**#import** pode, opcionalmente, incluir um ou mais atributos. Esses atributos instruem o compilador a modificar o conteúdo dos cabeçalhos de biblioteca de tipos. Um símbolo de barra **\\** invertida () pode ser usado para incluir linhas adicionais em uma única instrução de **#import** . Por exemplo:

```cpp
#import "test.lib" no_namespace \
   rename("OldName", "NewName")
```

Para obter mais informações, consulte [atributos de #import](../preprocessor/hash-import-attributes-cpp.md).

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)\
[Suporte a COM do compilador](../cpp/compiler-com-support.md)
