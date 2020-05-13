---
title: Páginas de propriedade do vinculador
ms.date: 07/24/2019
ms.topic: article
ms.assetid: 7e7671e5-a35a-4e67-9bdb-661d75c4d11e
ms.openlocfilehash: 2f2068c6c51fc6bf4e4104213e946e243fc6df2e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336581"
---
# <a name="linker-property-pages"></a>Páginas de propriedade do vinculador

As seguintes propriedades são encontradas no **Linker** > **Properties** > **de propriedades de** > configuração do**projeto**. Para obter mais informações sobre o linker, consulte [CL Invoca as Opções linker](cl-invokes-the-linker.md) e [linker](linker-options.md).

## <a name="general-property-page"></a>Página de propriedades gerais

### <a name="output-file"></a>Arquivo de saída

A opção [/OUT](out-output-file-name.md) substitui o nome padrão e o local do programa que o linker cria.

### <a name="show-progress"></a>Mostrar progresso

Imprime mensagens de progresso do linker

**Opções**

- **Não definido** - Sem verbosidade.
- **Exibir todas as mensagens de progresso** - Exibe todas as mensagens de progresso.
- **Para bibliotecas pesquisadas** - exibe mensagens de progresso indicando apenas as bibliotecas pesquisadas.
- **Sobre o COMDAT dobrável durante a vinculação otimizada** - Exibe informações sobre o dobrável COMDAT durante a vinculação otimizada.
- **Sobre os dados removidos durante a vinculação otimizada** - Exibe informações sobre funções e dados removidos durante a vinculação otimizada.
- **Sobre módulos incompatíveis com SEH** - Exibe informações sobre módulos incompatíveis com o Tratamento de Exceção Segura.
- **Sobre a atividade do linker relacionada ao código gerenciado** - Exibir informações sobre a atividade do linker relacionadas ao código gerenciado.

### <a name="version"></a>Versão

A opção [/VERSION](version-version-information.md) diz ao linker para colocar um número de versão no cabeçalho do arquivo .exe ou .dll. Use DUMPBIN /CABEÇALOS para ver o campo de versão de imagem dos VALORES DE CABEÇALHO OPCIONAIS para ver o efeito de **/VERSION**.

### <a name="enable-incremental-linking"></a>Habilitar vinculação incremental

Permite a vinculação incremental. ([/INCREMENTAL](incremental-link-incrementally.md)/ INCREMENTAL:NÃO)

### <a name="suppress-startup-banner"></a>Suprimir Faixa de Inicialização

A opção [/NOLOGO](nologo-suppress-startup-banner-linker.md) impede a exibição da mensagem de direitos autorais e do número da versão.

### <a name="ignore-import-library"></a>Ignorar Biblioteca de Importação

Essa propriedade instrui o vinculador a não vincular nenhuma saída .lib gerada por esse build a nenhum projeto dependente. Ele permite que o sistema de projeto manuseie arquivos .dll que não produzem um arquivo .lib quando construído. Se um projeto depende de outro projeto que produz uma DLL, o sistema do projeto vincula automaticamente o arquivo .lib produzido por esse projeto filho. Essa propriedade pode ser desnecessária em projetos que produzem DLLs COM ou DLLs somente com recursos, porque esses DLLs não têm exportações significativas. Se uma DLL não tiver exportações, o linker não gerará um arquivo .lib. Se nenhum arquivo .lib exportar estiver presente e o sistema do projeto disser ao linker para vincular com a DLL em falta, o link falhará. Use a propriedade **Ignorar Biblioteca de Importação** para resolver esse problema. Quando definido como **Sim,** o sistema de projeto ignora a presença ou ausência do arquivo .lib e faz com que qualquer projeto que dependa deste projeto não se vincule ao arquivo .lib inexistente.

Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreImportLibrary%2A>.

### <a name="register-output"></a>Registrar Saída

Executa `regsvr32.exe /s $(TargetPath)` na saída de build, que é válido somente em projetos .dll. Para projetos .exe, essa propriedade é ignorada. Para registrar uma saída .exe, defina um evento pós-build na configuração para fazer o registro personalizado que é sempre necessário para arquivos .exe registrados.

Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.RegisterOutput%2A>.

### <a name="per-user-redirection"></a>Redirecionamento por usuário

Tradicionalmente, o registro no Visual Studio é feito em HKEY_CLASSES_ROOT (HKCR). Com o Windows Vista e sistemas operacionais posteriores, para acessar HKCR, é necessário executar o Visual Studio no modo elevado. Os desenvolvedores nem sempre querem ser executados no modo elevado, mas ainda devem trabalhar com o registro. O redirecionamento por usuário permite que você se registre sem ter que ser executado no modo elevado.

O redirecionamento por usuário força as gravações em HKCR a serem redirecionadas para HKEY\_CURRENT\_USER (HKCU). Se o redirecionamento por usuário estiver desativado, isso poderá causar o [Erro de Build PRJ0050 do Projeto](../../error-messages/tool-errors/project-build-error-prj0050.md) quando o programa tentar fazer uma gravação em HKCR.

### <a name="additional-library-directories"></a>Diretórios de Biblioteca Adicionais

Permite que o usuário substitua o caminho da biblioteca ambiental. ([/LIBPATH](libpath-additional-libpath.md):pasta)

### <a name="link-library-dependencies"></a>Dependências da Biblioteca de Links

Especifica se os arquivos .lib produzidos por projetos dependentes devem ser vinculados. Normalmente, você deseja vincular nos arquivos .lib, mas pode não ser o caso de certos DLLs.

Especifique também um arquivo .obj fornecendo o nome de arquivo e o caminho relativo, por exemplo, "..\\..\MyLibProject\MyObjFile.obj". Se o código-fonte do arquivo .obj #includes um cabeçalho pré-compilado, por exemplo pch.h, então o arquivo pch.obj está localizado na mesma pasta que MyObjFile.obj. Você também deve adicionar pch.obj como uma dependência adicional.

### <a name="use-library-dependency-inputs"></a>Usar Entradas de Dependência da Biblioteca

Especifica se deve usar as entradas na ferramenta bibliotecária, em vez do próprio arquivo de biblioteca, ao vincular em saídas de biblioteca saem de dependências de projetos. Em um projeto grande, quando um projeto dependente produz um arquivo .lib, o vínculo incremental é desabilitado. Se houver muitos projetos dependentes que produzem arquivos .lib, a compilação do aplicativo poderá levar muito tempo. Quando esta propriedade é definida como **Sim,** o sistema de projeto se conecta nos arquivos .obj para .libs produzidos por projetos dependentes, permitindo a vinculação incremental.

Para obter informações sobre como acessar a página de propriedade do linker **geral,** consulte [O compilador Set C++ e construa propriedades no Visual Studio](../working-with-project-properties.md).

### <a name="link-status"></a>Status do Link

Especifica se o linker deve exibir um indicador de progresso mostrando qual porcentagem do link está concluído. O padrão é não exibir essas informações de status. ([/LTCG](ltcg-link-time-code-generation.md):STATUS| LTCG:NOSTATUS)

### <a name="prevent-dll-binding"></a>Impedir a ligação da DLL

[/ALLOWBIND](allowbind-prevent-dll-binding.md):NO define um pouco no cabeçalho de uma DLL que indica para Bind.exe que a imagem não está autorizada a ser vinculada. Talvez você não queira que uma DLL seja vinculada caso ela tenha sido assinada digitalmente (a associação invalida a assinatura).

### <a name="treat-linker-warning-as-errors"></a>Tratar aviso do linker como erros

[/WX](wx-treat-linker-warnings-as-errors.md) faz com que nenhum arquivo de saída seja gerado se o linker gerar um aviso.

### <a name="force-file-output"></a>Saída do arquivo de força

A opção [/FORCE](force-force-file-output.md) diz ao linker para criar um arquivo .exe ou DLL mesmo se um símbolo for referenciado, mas não definido, ou for multiplicado definido. Ele pode criar arquivo .exe inválido.

**Opções**

- **Ativado** - /FORCE sem argumentos implica múltiplos e não resolvidos.
- **Multiplique somente símbolo definido** - Use /FORCE:MULTIPLE para criar um arquivo de saída, mesmo se o LINK encontrar mais de uma definição para um símbolo.
- **Somente símbolo indefinido** - Use /FORCE:UNRESOLVED para criar um arquivo de saída se o LINK encontra ou não um símbolo indefinido. /FORCE:UNRESOLVED é ignorado se o símbolo do ponto de entrada não for resolvido.

### <a name="create-hot-patchable-image"></a>Criar imagem patchable quente

Prepara uma imagem para hotpatching.

**Opções**

- **Ativado** - Prepara uma imagem para hotpatching.
- **X86 Image Only** - Prepara uma imagem X86 para hotpatching.
- **X64 Image Only** - Prepara uma imagem X64 para hotpatching.
- **Somente imagem de Itanium** - Prepara uma imagem de Itanium para hotpatching.

### <a name="specify-section-attributes"></a>Especificar atributos de seção

A opção [/SECTION](section-specify-section-attributes.md) altera os atributos de uma seção, substituindo os atributos definidos quando o arquivo .obj para a seção foi compilado.

## <a name="input-property-page"></a>Página de propriedade de entrada

### <a name="additional-dependencies"></a>Dependências adicionais

Especifica itens adicionais para adicionar à linha de comando link, por *exemplo, kernel32.lib*.

### <a name="ignore-all-default-libraries"></a>Ignorar todas as bibliotecas padrão

A opção [/NODEFAULTLIB](nodefaultlib-ignore-libraries.md) diz ao linker para remover uma ou mais bibliotecas padrão da lista de bibliotecas que ele pesquisa ao resolver referências externas.

### <a name="ignore-specific-default-libraries"></a>Ignorar bibliotecas padrão específicas

Especifica um ou mais nomes de bibliotecas padrão a serem ignoradas. Separe várias bibliotecas com ponto e vírgula. (/NODEFAULTLIB:[nome, nome, ...])

### <a name="module-definition-file"></a>Arquivo de definição de módulo

A opção [/DEF](def-specify-module-definition-file.md) passa um arquivo de definição de módulo (.def) para o linker. Apenas um arquivo .def pode ser especificado para LINK.

### <a name="add-module-to-assembly"></a>Adicionar módulo ao assembly

A opção [/ASSEMBLYMODULE](assemblymodule-add-a-msil-module-to-the-assembly.md) permite adicionar uma referência de módulo a um conjunto. As informações de digitação no módulo não estarão disponíveis para o programa de montagem que adicionou a referência do módulo. No entanto, informações de tipo no módulo estarão disponíveis para qualquer programa que refira a montagem.

### <a name="embed-managed-resource-file"></a>Incorporar arquivo de recursos gerenciados

[/ASSEMBLYRESOURCE](assemblyresource-embed-a-managed-resource.md) incorpora um arquivo de recursos no arquivo de saída.

### <a name="force-symbol-references"></a>Forçar referências de símbolo

A opção [/INCLUDE](include-force-symbol-references.md) diz ao linker para adicionar um símbolo especificado à tabela de símbolos.

### <a name="delay-loaded-dlls"></a>DLLs carregados de atraso

A opção [/DELAYLOAD](delayload-delay-load-import.md) causa o carregamento atrasado de DLLs. O nome dll especifica uma DLL para atrasar a carga.

### <a name="assembly-link-resource"></a>Recurso de link de montagem

A opção [/ASSEMBLYLINKRESOURCE](assemblylinkresource-link-to-dotnet-framework-resource.md) cria um link para um recurso .NET Framework no arquivo de saída; o arquivo de recurso não é colocado no arquivo de saída.

## <a name="manifest-file-property-page"></a>Página de propriedade do arquivo manifesto

### <a name="generate-manifest"></a>Gerar Manifesto

[/MANIFEST](manifest-create-side-by-side-assembly-manifest.md) especifica que o linker deve criar um arquivo manifesto lado a lado.

### <a name="manifest-file"></a>Arquivo manifesto

[/MANIFESTFILE](manifestfile-name-manifest-file.md) permite alterar o nome padrão do arquivo manifesto. O nome padrão do arquivo manifesto é o nome do arquivo com .manifest anexado.

### <a name="additional-manifest-dependencies"></a>Dependências de manifesto adicionais

[/MANIFESTDEPENDENCY](manifestdependency-specify-manifest-dependencies.md) permite especificar atributos que serão colocados na seção de dependência do arquivo manifesto.

### <a name="allow-isolation"></a>Permitir isolamento

Especifica o comportamento da pesquisa de manifesto. ([/ALLOWISOLATION](allowisolation-manifest-lookup.md):NO)

### <a name="enable-user-account-control-uac"></a>Habilitar o controle da conta de usuário (UAC)

Especifica se o controle da conta de usuário está ativado ou não.  ([/MANIFESTUAC](manifestuac-embeds-uac-information-in-manifest.md), /MANIFESTUAC:NO)

### <a name="uac-execution-level"></a>Nível de execução do UAC

Especifica o nível de execução solicitado para o aplicativo ao ser executado com controle de conta de usuário.  (/MANIFESTUAC:level=[value])

**Opções**

- **asInvoker** - Nível de execução UAC: como invocador.
- **mais altoDisponível** - Nível de execução UAC: mais alto disponível.
- **exigirAdministrador** - Nível de execução UAC: exigir administrador.

### <a name="uac-bypass-ui-protection"></a>Proteção da uac bypass ui

Especifica se deve ou não ignorar os níveis de proteção da interface do usuário para outras janelas na área de trabalho.  Defina esta propriedade como 'Sim' apenas para aplicativos de acessibilidade.  ([/MANIFESTUAC](manifestuac-embeds-uac-information-in-manifest.md)/MANIFESTUAC:uiAccess=[true | false])

## <a name="debugging-property-page"></a>Página de propriedade de depuração

### <a name="generate-debug-info"></a>Gerar informações de depuração

Essa opção permite a criação de informações de depuração para o arquivo .exe ou para o DLL.

**Opções**

- **Não** - Não produz informações de depuração.
- **Gerar informações de depuração** - Crie um PDB (Program Database) completo ideal para distribuição ao Microsoft Symbol Server.
- **Gerar informações de depuração otimizadas para links mais rápidos** - Produz um banco de dados de programa (PDB) ideal para o ciclo de edição-link-depuração.
- **Gerar Informações de depuração otimizadas para compartilhamento e publicação** - Produz um banco de dados de programas (PDB) ideal para o ciclo de edição-link-depuração.

### <a name="generate-program-database-file"></a>Gerar arquivo de banco de dados do programa

Por padrão, quando [/DEBUG](debug-generate-debug-info.md) é especificado, o linker cria um banco de dados de programa (PDB) que contém informações de depuração. O nome do arquivo padrão do PDB tem o nome base do programa e a extensão .pdb.

### <a name="strip-private-symbols"></a>Símbolos privados de tiras

A opção [/PDBSTRIPPED](pdbstripped-strip-private-symbols.md) cria um segundo arquivo de banco de dados de programa (PDB) quando você constrói sua imagem de programa com qualquer uma das opções de compilador ou linker que geram um arquivo PDB (/DEBUG, /Z7, /Zd ou /Zi).

### <a name="generate-map-file"></a>Gerar arquivo de mapa

A opção [/MAP](map-generate-mapfile.md) diz ao linker para criar um arquivo de mapa.

### <a name="map-file-name"></a>Nome de Arquivo de Mapa

Um nome especificado pelo usuário para o arquivo de mapa. Ele substitui o nome padrão.

### <a name="map-exports"></a>Mapa de Exportações

A opção [/MAPINFO](mapinfo-include-information-in-mapfile.md) informa ao linker para incluir as informações especificadas em um arquivo de mapa, que é criada se você especificar a opção /MAP. Exportações informa o linker para incluir funções exportadas.

### <a name="debuggable-assembly"></a>Montagem depurada

[/ASSEMBLYDEBUG](assemblydebug-add-debuggableattribute.md) emite o atributo DepuravelAttribute com o rastreamento de informações de depuração e desativa otimizações do JIT.

## <a name="system-property-page"></a>Página de propriedade do sistema

### <a name="subsystem"></a>Subsistema

A opção [/SUBSYSTEM](subsystem-specify-subsystem.md) informa ao sistema operacional como executar o arquivo .exe. A escolha do subsistema afeta o símbolo de ponto de entrada (ou função de ponto de entrada) que o linker escolherá.

**Opções**

- **Não definido** - Nenhum conjunto de subsistema.
- **Console** - Aplicativo de modo de caractere sinuoso Win32. Os aplicativos de console recebem um console pelo sistema operacional. Se principal ou wmain for definido, CONSOLE é o padrão.
- **Windows** - Aplicativo não requer um console, provavelmente porque cria suas próprias janelas para interação com o usuário. Se winmain ou wWinMain for definido, o WINDOWS será o padrão.
- **Nativo** - Drivers de dispositivo para Windows NT. Se /DRIVER:WDM for especificado, NATIVE é o padrão.
- **Aplicação EFI** - Aplicação EFI.
- **Driver do serviço de inicialização EFI** - Driver de serviço de inicialização EFI.
- **Rom EFI** - Rom EFI.
- **EFI Runtime** - EFI Runtime.
- **POSIX** - Aplicativo que é executado com o subsistema POSIX no Windows NT.

### <a name="minimum-required-version"></a>Versão mínima necessária

Especifique a versão mínima exigida do subsistema. Os argumentos são números decimais na faixa de 0 a 65.535.

### <a name="heap-reserve-size"></a>Tamanho da reserva de pilha

Especifica o tamanho total da alocação de pilhas na memória virtual. O padrão é de 1 MB.    ([/HEAP](heap-set-heap-size.md):reserva)

### <a name="heap-commit-size"></a>Tamanho do compromisso de pilha

Especifica o tamanho total da alocação de pilhas na memória física. O padrão é 4 KB.    ([/HEAP](heap-set-heap-size.md):reserve,commit)

### <a name="stack-reserve-size"></a>Tamanho da reserva de pilha

Especifica o tamanho de alocação de pilha total em memória virtual. O padrão é de 1 MB.     ([/STACK](stack-stack-allocations.md):reserva)

### <a name="stack-commit-size"></a>Tamanho do compromisso de pilha

Especifica o tamanho total da alocação da pilha na memória física. O padrão é 4 KB.     ([/STACK](stack-stack-allocations.md):reserve,commit)

### <a name="enable-large-addresses"></a>Habilite endereços grandes

A opção [/LARGEADDRESSAWARE](largeaddressaware-handle-large-addresses.md) informa ao linker que o aplicativo pode lidar com endereços maiores que 2 gigabytes. Por padrão, /LARGEADDRESSAWARE:NO está ativado se /LARGEADDRESSAWARE não for especificado de outra forma na linha linker.

### <a name="terminal-server"></a>Terminal Server

A opção [/TSAWARE](tsaware-create-terminal-server-aware-application.md) define um sinalizador no campo IMAGE_OPTIONAL_HEADER DllCharacteristics no cabeçalho opcional da imagem do programa. Quando esse sinalizador estiver definido, o servidor Host da Sessão da Área de Trabalho Remota não fará certas alterações no aplicativo.

### <a name="swap-run-from-cd"></a>Swap Run From CD

A opção [/SWAPRUN](swaprun-load-linker-output-to-swap-file.md) informa o sistema operacional para primeiro copiar a saída do linker para um arquivo de swap e, em seguida, executar a imagem a partir daí. Esta opção é um recurso do Windows NT 4.0 (e posterior). Quando **o CD** for especificado, o sistema operacional copiará a imagem em um disco removível em um arquivo de página e, em seguida, carregá-la.

### <a name="swap-run-from-network"></a>Swap Run From Network

A opção [/SWAPRUN](swaprun-load-linker-output-to-swap-file.md) informa o sistema operacional para primeiro copiar a saída do linker para um arquivo de swap e, em seguida, executar a imagem a partir daí. Esta opção é um recurso do Windows NT 4.0 (e posterior). Se **o NET** for especificado, o sistema operacional primeiro copiará a imagem binária da rede para um arquivo de troca e a carregará a partir daí. Esta opção é útil para executar aplicativos na rede.

### <a name="driver"></a>Driver

Use a opção [/DRIVER](driver-windows-nt-kernel-mode-driver.md) linker para criar um driver de modo de kernel do Windows NT.

**Opções**

- **Não definido** - Configuração padrão do driver.
- **Motorista** - Motorista
- **SOMENTE PARA CIMA** - /DRIVER:UPSÓ faz com que o linker adicione o bit IMAGE_FILE_UP_SYSTEM_ONLY às características do cabeçalho de saída para especificar que ele é um driver uniprocessador (UP). O sistema operacional se recusará a carregar um driver UP em um sistema de multiprocessador (MP).
- **WDM** - /DRIVER:WDM faz com que o linker defina o bit IMAGE_DLLCHARACTERISTICS_WDM_DRIVER no campo DllCharacteristics do cabeçalho opcional.

## <a name="optimization-property-page"></a>Página de propriedade de otimização

### <a name="references"></a>Referências

[/OPT](opt-optimizations.md):REF elimina funções e/ou dados que nunca foram referenciados enquanto /OPT:NOREF mantém funções e/ou dados que nunca foram referenciados.

### <a name="enable-comdat-folding"></a>Habilitar Dobra COMDAT

Use [/OPT](opt-optimizations.md):ICF\[=iterações] para executar a dobra COMDAT idêntica.

### <a name="function-order"></a>Ordem de função

A opção [/ORDER](order-put-functions-in-order.md)diz ao LINK para otimizar seu programa colocando certos COMDATs na imagem em uma ordem pré-determinada. LINK coloca as funções na ordem especificada dentro de cada seção na imagem.

### <a name="profile-guided-database"></a>Banco de dados guiado por perfil

Especifique o arquivo .pgd para otimizações guiadas por perfil. ([/PGD](pgd-specify-database-for-profile-guided-optimizations.md))

### <a name="link-time-code-generation"></a>Geração de Código Durante o Tempo de Vinculação

Especifica a geração do código de tempo de vinculação. ([/LTCG)](ltcg-link-time-code-generation.md)

**Opções**

- **Padrão** - Configuração padrão do LTCG.
- **Use geração de código de tempo de link rápido** - Use a geração de código de tempo de link com [/FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md).
- **Use a geração de código de tempo de link** - Use a geração de código de tempo de [link](ltcg-link-time-code-generation.md).
- **Otimização Guiada de Perfil - Instrumento** - Use [otimização guiada por perfil](../profile-guided-optimizations.md) com :PGINSTRUMENT.
- **Otimização guiada de perfil - Otimização** - Especifica que o linker deve usar os dados de perfil criados após a execução do binário instrumentado para criar uma imagem otimizada.
- **Otimização guiada de perfil - Atualização** - Permite e rastreia lista de arquivos de entrada a serem adicionados ou modificados do que foi especificado na fase :PGINSTRUMENT.

## <a name="embedded-idl-property-page"></a>Página de propriedade idl incorporada

### <a name="midl-commands"></a>Comandos MIDL

Especifique opções de linha de comando MIDL. ([/MIDL](midl-specify-midl-command-line-options.md):@responsefile)

### <a name="ignore-embedded-idl"></a>Ignorar IDL incorporado

A opção [/IGNOREIDL](ignoreidl-don-t-process-attributes-into-midl.md) especifica que quaisquer atributos IDL no código-fonte não devem ser processados em um arquivo .idl.

### <a name="merged-idl-base-file-name"></a>Nome do arquivo base do IDL mesclado

A opção [/IDLOUT](idlout-name-midl-output-files.md) especifica o nome e a extensão do arquivo .idl.

### <a name="type-library"></a>Biblioteca de tipos

A opção [/TLBOUT](tlbout-name-dot-tlb-file.md) especifica o nome e a extensão do arquivo .tlb.

### <a name="typelib-resource-id"></a>ID de recurso TypeLib

Permite especificar o ID de recurso da biblioteca de tipos gerada pelo linker. ([/TLBID](tlbid-specify-resource-id-for-typelib.md):id)

## <a name="windows-metadata-property-page"></a>Página de propriedade de metadados do Windows

### <a name="generate-windows-metadata"></a>Gerar metadados do Windows

Habilita ou desativa a geração de Metadados do Windows.

**Opções**

- **Sim** - Habilitar a geração de arquivos De Metadados do Windows.
- **Não** - Desativar a geração de arquivos Metadados do Windows.

### <a name="windows-metadata-file"></a>Arquivo de metadados do Windows

O interruptor da opção [/WINMDFILE.](winmdfile-specify-winmd-file.md)

### <a name="windows-metadata-key-file"></a>Arquivo de chave de metadados do Windows

Especifique a chave ou o par de tecla para assinar um Metadados do Windows. ([/WINMDKEYFILE](winmdkeyfile-specify-winmd-key-file.md):nome do arquivo)

### <a name="windows-metadata-key-container"></a>Contêiner de chave de metadados do Windows

Especifique um contêiner de chaves para assinar um Metadados do Windows. ([/WINMDKEYCONTAINER](winmdkeycontainer-specify-key-container.md):nome)

### <a name="windows-metadata-delay-sign"></a>Sinal de atraso de metadados do Windows

Assine parcialmente um Metadados do Windows. Use [/WINMDDELAYSIGN](winmddelaysign-partially-sign-a-winmd.md) se você quiser apenas colocar a chave pública nos Metadados do Windows. O padrão é /WINMDDELAYSIGN:NO.

## <a name="advanced-property-page"></a>Página de propriedade avançada

### <a name="entry-point"></a>Entry Point

A opção [/ENTRY](entry-entry-point-symbol.md) especifica uma função de ponto de entrada como endereço inicial de um arquivo .exe ou DLL.

### <a name="no-entry-point"></a>Sem ponto de entrada

A [opção /NOENTRY](noentry-no-entry-point.md)é necessária para criar uma DLL somente para recursos. Use esta opção para impedir que `_main` o LINK vincule uma referência à DLL.

### <a name="set-checksum"></a>Definir checkum

A opção /RELEASE define o ['''''Liberar',](release-set-the-checksum.md) o '''exe'.

### <a name="base-address"></a>Endereço básico

Define um endereço básico para o programa. ([/BASE](base-base-address.md):{endereço\[,tamanho] | @filename,chave})

### <a name="randomized-base-address"></a>Endereço base randomizado

Endereço base randomizado. ([/DYNAMICBASE](dynamicbase-use-address-space-layout-randomization.md)\[:NO])

### <a name="fixed-base-address"></a>Endereço base fixo

Cria um programa que só pode ser carregado em seu endereço básico preferido. ([/FIXO](fixed-fixed-base-address.md)\[:NÃO))

### <a name="data-execution-prevention-dep"></a>Prevenção de Execução de Dados (DEP)

Marca um executável como tendo sido testado para ser compatível com o recurso de prevenção de execução de dados do Windows. ([/NXCOMPAT](nxcompat-compatible-with-data-execution-prevention.md)\[:NO])

### <a name="turn-off-assembly-generation"></a>Desativar a geração de montagem

A opção [/NOASSEMBLY](noassembly-create-a-msil-module.md) diz ao linker para criar uma imagem para o arquivo de saída atual sem um conjunto .NET Framework.

### <a name="unload-delay-loaded-dll"></a>Descarregar dll carregado de atraso

O qualificador **UNLOAD** informa a função de auxiliar de carga de atraso para suportar o descarregamento explícito da DLL. ([/DELAY](delay-delay-load-import-settings.md):UNLOAD)

### <a name="nobind-delay-loaded-dll"></a>Atraso nobind carregado DLL

O qualificador **NOBIND** diz ao linker para não incluir um IAT vinculável na imagem final. O padrão é criar a IAT associável para DLLs carregadas com atraso. ([/DELAY](delay-delay-load-import-settings.md):NOBIND)

### <a name="import-library"></a>Bibliotecas de importação

Substitui o nome da biblioteca de importação padrão. ([/IMPLIB](implib-name-import-library.md):nome de arquivo)

### <a name="merge-sections"></a>Seções de mesclagem

A opção [/MERGE](merge-combine-sections.md) combina a primeira seção (de) com a segunda seção (para), nomeando a seção resultante para. Por exemplo, /merge:.rdata=.text.

### <a name="target-machine"></a>Máquina alvo

A opção [/MACHINE](machine-specify-target-platform.md) especifica a plataforma de destino do programa.

**Opções**

- **Não definido**
- **Armdea-máquina**
- **MachineARM64**
- **MáquinaEBC**
- **MachineIA64**
- **MachineMIPS**
- **MachineMIPS16**
- **MachineMIPSFPU**
- **MachineMIPSFPU16**
- **MáquinasH4**
- **Polegar de máquina**
- **MáquinaX64**
- **MáquinaX86**

### <a name="profile"></a>Perfil

Produz um arquivo de saída que pode ser usado com o criador de perfil de Ferramentas de desempenho. Requer que gerardepurainformação (/[/DEBUG)](debug-generate-debug-info.md)seja definido. ([/PERFIL)](profile-performance-tools-profiler.md)

### <a name="clr-thread-attribute"></a>Atributo de rosca CLR

Especifique explicitamente o atributo de rosca para o ponto de entrada do seu programa CLR.

**Opções**

- **Atributo de threading MTA** - Aplica o atributo MTAThreadAttribute ao ponto de entrada do programa.
- **Atributo de threading STA** - Aplica o atributo STAThreadAttribute ao ponto de entrada do programa.
- **Atributo de rosca padrão** - O mesmo que não especificar [/CLRTHREADATTRIBUTE](clrthreadattribute-set-clr-thread-attribute.md). Permite que o CLR (Common Language Runtime, tempo de execução do idioma comum) defina o atributo de rosca padrão.

### <a name="clr-image-type"></a>Tipo de imagem CLR

Define o tipo (IJW, puro ou seguro) de uma imagem do CLR.

**Opções**

- **Imagem da Force IJW**
- **Force Pure IL Image**
- **Force Safe IL Image**
- **Tipo de imagem padrão**

### <a name="key-file"></a>Arquivo de chave

Especifique a tecla ou o par de tecla para assinar um conjunto. ([/KEYFILE](keyfile-specify-key-or-key-pair-to-sign-an-assembly.md):nome do arquivo)

### <a name="key-container"></a>Recipiente chave

Especifique um recipiente-chave para assinar uma montagem. ([/KEYCONTAINER](keycontainer-specify-a-key-container-to-sign-an-assembly.md):name)

### <a name="delay-sign"></a>Sinal de atraso

Assine parcialmente uma assembléia. Use [/DELAYSIGN](delaysign-partially-sign-an-assembly.md) se você só quiser colocar a chave pública na montagem. O padrão é /DELAYSIGN:NO.

### <a name="clr-unmanaged-code-check"></a>Verificação de código não gerenciada clr

[/CLRUNMANAGEDCODECHECK](clrunmanagedcodecheck-add-suppressunmanagedcodesecurityattribute.md) especifica se o linker aplicará O SupressoUnmanagedCodeSecurityAttribute a chamadas PInvoke geradas por link de código gerenciado em DLLs nativos.

### <a name="error-reporting"></a>Relatório de Erros

Permite fornecer informações de ICE (erro interno do compilador) diretamente à equipe do Visual C++.

**Opções**

- **AvisoImediatamente** - Solicitar imediatamente.
- **Fila para o próximo login** - Fila para o próximo login.
- **Enviar relatório de erro** - Enviar relatório de erro.
- **Sem relatório de erro** - Nenhum relatório de erro.

### <a name="sectionalignment"></a>SectionAlignment

A opção [/ALIGN](align-section-alignment.md) especifica o alinhamento de cada seção dentro do espaço de endereço linear do programa. O argumento numérdia está em bytes e deve ser um poder de dois.

### <a name="preserve-last-error-code-for-pinvoke-calls"></a>Preservar o último código de erro para chamadas PInvoke

[/CLRSUPPORTLASTERROR](clrsupportlasterror-preserve-last-error-code-for-pinvoke-calls.md), que está ligado por padrão, preserva o último código de erro das funções chamadas através do mecanismo P/Invoke, que permite chamar funções nativas em DLLS, a partir de código compilado com /clr.

**Opções**

- **Ativado** - Habilitar CLRSupportLastError.
- **Desativado** - Desativar CLRSupportLastError.
- **Somente dlls do sistema** - Habilite clrSupportLastError apenas para dlls do sistema.

### <a name="image-has-safe-exception-handlers"></a>A imagem tem manipuladores de exceção seguros

Quando [/SAFESEH](safeseh-image-has-safe-exception-handlers.md) for especificado, o linker só produzirá uma imagem se ele também puder produzir uma tabela dos manipuladores de exceção seguros da imagem. Esta tabela especifica para o sistema operacional quais manipuladores de exceção são válidos para a imagem.
