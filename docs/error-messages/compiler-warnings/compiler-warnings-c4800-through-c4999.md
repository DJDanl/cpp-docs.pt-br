---
title: Avisos do compilador C4800 por meio de C4999 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4806
- C4807
- C4810
- C4811
- C4812
- C4813
- C4816
- C4817
- C4822
- C4825
- C4827
- C4872
- C4880
- C4881
- C4882
- C4900
- C4910
- C4912
- C4913
- C4916
- C4918
- C4920
- C4921
- C4925
- C4926
- C4932
- C4934
- C4935
- C4936
- C4937
- C4938
- C4939
- C4944
- C4947
- C4950
- C4951
- C4952
- C4953
- C4954
- C4955
- C4956
- C4957
- C4958
- C4959
- C4960
- C4961
- C4962
- C4963
- C4966
- C4970
- C4971
- C4972
- C4973
- C4974
- C4981
- C4985
- C4987
- C4988
- C4989
- C4990
- C4991
- C4992
- C4997
- C4998
- C4999
- C4808
- C4809
dev_langs:
- C++
ms.assetid: c3182430-8b3b-4ab2-a532-5cd436707dc8
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 65e7a7bd56096fbeec61b651ab494d82edef9c90
ms.openlocfilehash: a30a9d6a60890d0fbb4abf78df8fda4631340a6d
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warnings-c4800-through-c4999"></a>Avisos do compilador C4800 por meio de C4999
Os artigos nesta parte da documentação contêm informações sobre um subconjunto de avisos do compilador do Visual C++. Você pode acessar as informações aqui ou, na janela de saída no Visual Studio, você pode selecionar um número de erro e, em seguida, pressione a tecla F1.  
  
## <a name="in-this-section"></a>Nesta seção  
  
|Aviso|Mensagem|  
|-------------|-------------|  
|[Aviso (nível 3) do compilador C4800](../../error-messages/compiler-warnings/compiler-warning-level-3-c4800.md)|'type': forçar o valor bool 'true' ou 'false' (aviso de desempenho)|  
|[Compilador C4803 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4803.md)|'method': o método para disparar tem uma classe de armazenamento diferente do evento, 'event'|  
|[Compilador C4804 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4804.md)|'operation': uso não seguro do tipo bool em operação|  
|[Compilador C4805 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4805.md)|'operation': unsafe combinação do tipo 'type' e tipo 'type' em operação|  
|Aviso do compilador (nível 1) C4806|'operation': operação unsafe: nenhum valor do tipo 'type' promovido para o tipo 'type' pode ser igual a constante determinada|  
|Aviso do compilador (nível 1) C4807|'operation': unsafe mistura de tipo 'type' e o campo de bits assinado do tipo 'type'|  
|Aviso do compilador (nível 1) C4808|Caso 'value' não é um valor válido para a condição de comutador do tipo 'booleano'|  
|Aviso do compilador (nível 1) C4809|instrução switch possui rótulo 'default' redundante; todos os rótulos 'case' possíveis são fornecidos|  
|Aviso do compilador (nível 1) C4810|valor de pragma pack(show) = = n|  
|Aviso do compilador (nível 1) C4811|valor de pragma em conformidade (Mostrar forScope) = = valor|  
|Aviso do compilador (nível 1) C4812|estilo de declaração e obsoleto: em vez disso, use 'new_syntax'|  
|Aviso do compilador (nível 1) C4813|'function': uma função friend de uma classe local deve ter sido anteriormente declarada|  
|Aviso do compilador (nível 4) C4816|'param': o parâmetro tem uma matriz de tamanho zero que será truncada (a menos que o objeto é passado por referência)|  
|Aviso do compilador (nível 1) C4817|'member': uso inválido de '.' para acessar esse membro; compilador substituído por '->'|  
|[C4819 do compilador (nível 1) de aviso](../../error-messages/compiler-warnings/compiler-warning-level-1-c4819.md)|O arquivo contém um caractere que não pode ser representado na página de código atual (número). Salve o arquivo em formato Unicode para evitar a perda de dados|  
|[Compilador C4820 de aviso (nível 4)](../../error-messages/compiler-warnings/compiler-warning-level-4-c4820.md)|preenchimento de bytes 'bytes' adicionado após construção de 'member_name'|  
|[Compilador C4821 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4821.md)|Não é possível determinar tipo de codificação Unicode, salve o arquivo com assinatura (BOM)|  
|Aviso do compilador (nível 1) C4822|'função de membro': função de membro de classe local não tem um corpo|  
|[Compilador C4823 de aviso (nível 3)](../../error-messages/compiler-warnings/compiler-warning-level-3-c4823.md)|'function': usa ponteiros de fixação de desenrolamento mas semântica não está habilitada. Considere o uso de /EHa|  
|Aviso do compilador (nível 4) C4825||  
|Aviso do compilador (nível 3) C4827|Um método 'ToString' público com 0 parâmetro deve ser marcado como virtual e override|  
|[Compilador C4829 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4829.md)|Parâmetros possivelmente incorretos para a função principal. Considere ' int principal (Platform:: array\<Platform:: string ^ > ^ argv)'|  
|[Compilador C4835 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4835.md)|'variável': o inicializador de dados exportados não será executado até que o código gerenciado é executado pela primeira vez no assembly de host|  
|[Compilador C4838 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4838.md)|conversão de 'type_1' em 'type_2' requer uma conversão de restrição|  
|[C4867 de aviso do compilador](../../error-messages/compiler-warnings/compiler-warning-c4867.md)|'function': a chamada de função ausente da lista de argumentos; Use 'ligação' para criar um ponteiro para membro|  
|[C4868 de aviso do compilador](../../error-messages/compiler-warnings/compiler-warning-c4868.md)|compilador 'file(line_number)' não pode impor a ordem de avaliação da esquerda para a direita na lista de inicialização entre chaves|  
|Aviso do compilador (nível 2) C4872|divisão de ponto flutuante por zero detectada ao compilar o gráfico de chamada concurrency::parallel_for_each em: '%s'|  
|Aviso do compilador (nível 1) C4880|conversão de 'const type_1' em 'type_2': conversão imediatamente constness de um ponteiro ou referência pode resultar em um comportamento indefinido em uma função amp restringido|  
|Aviso do compilador (nível 4) C4881|o construtor e/ou o destruidor não será chamado para tile_static variável 'variável'|  
|Aviso do compilador (nível 1) C4882|a transmissão de functors com operadores de chamada não constantes para concurrency::parallel_for_each foi preterida|  
|C4900 de aviso do compilador|II incompatibilidade entre a versão de 'tool1' 'version1' e 'tool2' 'versão&2;'|  
|[Compilador C4905 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4905.md)|literal amplo de cadeia de caracteres convertido em 'LPSTR'|  
|[Compilador C4906 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4906.md)|literal de cadeia de caracteres convertido em 'LPWSTR'|  
|Aviso do compilador (nível 1) C4910|'\<identificador >: 'dllexport' e 'extern' são incompatíveis em uma instanciação explícita|  
|Aviso do compilador (nível 1) C4912|'attribute': atributo tem um comportamento em um UDT aninhado indefinido|  
|Aviso do compilador (nível 4) C4913|operador binário definido pelo usuário ',' existe mas nenhuma sobrecarga pôde converter todos os operando, operador binário interno padrão ',' usado|  
|Aviso do compilador (nível 1) C4916|a fim de possuir um dispid, '%$S': deve ser introduzido por uma interface|  
|[Compilador C4917 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4917.md)|'declarator': um GUID só pode ser associado uma classe, interface ou namespace|  
|Aviso do compilador (nível 4) C4918|'character': caractere inválido na lista de otimização do pragma|  
|Aviso do compilador (nível 1) C4920|enumeração enum membro member_1 = value_1 já vista na enumeração enum como member_2 = value_2|  
|Aviso do compilador (nível 3) C4921|'%s': valor de atributo '%s' não deve ser especificado várias vezes|  
|Aviso do compilador (nível 1) C4925|'method': método dispinterface não pode ser chamado de script|  
|Aviso do compilador (nível 1) C4926|'identifier': símbolo já está definido: atributos ignorados|  
|[Compilador C4927 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4927.md)|conversão inválida; mais de uma conversão definida pelo usuário foi aplicada implicitamente|  
|[Compilador C4928 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4928.md)|inicialização de cópia ilegal; mais de uma conversão definida pelo usuário foi implicitamente aplicada|  
|[Compilador C4929 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4929.md)|'arquivo': typelibrary contém uma união; Ignorando o qualificador 'embedded_idl'|  
|[Compilador C4930 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4930.md)|'protótipo de ': função protótipo não chamada (era uma definição de variável se destina?)|  
|[Compilador C4931 de aviso (nível 4)](../../error-messages/compiler-warnings/compiler-warning-level-4-c4931.md)|estamos supondo que a biblioteca de tipos foi criada para ponteiros de bit por número|  
|Aviso do compilador (nível 4) C4932|__identifier(Identifier) e \__identifier(identifier) não podem ser diferenciados|  
|Aviso do compilador (nível 1) C4934|'__delegate(multicast)' está obsoleto, use '\_delegate ' em vez disso|  
|Aviso do compilador (nível 1) C4935|especificador de acesso do assembly modificado de 'access'|  
|Aviso do compilador (nível 1) C4936|este __declspec é suportado apenas quando compilado com /clr ou com /clr:pure|  
|Aviso do compilador (nível 4) C4937|'text1' e 'text2' não podem ser diferenciados como argumentos para 'diretiva'|  
|Aviso do compilador (nível 4) C4938|'var': variável de redução de ponto flutuante pode causar resultados inconsistentes em /fp: strict ou #pragma fenv_access|  
|C4939 de aviso do compilador|#pragma vtordisp foi substituído e será removido em uma versão futura do Visual C++|  
|Aviso do compilador (nível 1) C4944|'symbol': não é possível importar o símbolo de 'assembly1': como 'symbol' já existe no escopo atual|  
|[Compilador C4945 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4945.md)|'symbol': não é possível importar o símbolo de 'assembly1': como 'symbol' já foi importada de outro assembly 'assembly2'|  
|[Compilador C4946 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4946.md)|reinterpret_cast usado entre classes relacionadas: 'class1' e 'class2'|  
|Aviso do compilador (nível 1) C4947|'type_or_member': marcados como obsoletos|  
|[Compilador C4948 de aviso (nível 2)](../../error-messages/compiler-warnings/compiler-warning-level-2-c4948.md)|tipo de retorno de 'acessador' não coincide com o último tipo de parâmetro do setter correspondente|  
|[Compilador C4949 de aviso (nível 1 e nível 4)](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4949.md)|Os pragmas '' e 'gerenciados' são significativos apenas quando compilado com ' / clr [: opção]'|  
|Aviso do compilador (nível 1) C4950|'type_or_member': marcados como obsoletos|  
|C4951 de aviso do compilador|'function' foi editada desde o perfil de dados foram coletados, os dados de perfil de função não usados|  
|C4952 de aviso do compilador|'function': nenhum dado de perfil encontrado no banco de dados do programa 'pgd_file'|  
|C4953 de aviso do compilador|Embutido 'function' foi editado desde o perfil de dados foram coletados, os dados de perfil não usados|  
|C4954 de aviso do compilador|'function': não atribuído (contém a expressão de switch Int64)|  
|C4955 de aviso do compilador|'import2': importação ignorada; já importados de 'import1'|  
|Aviso do compilador (nível 1) C4956|'type': esse tipo não é verificável|  
|Aviso do compilador (nível 1) C4957|'cast': conversão explícita de 'conversão de' para 'cast_to' não é verificável|  
|Aviso do compilador (nível 1) C4958|'operation': aritmética de ponteiro não é verificável|  
|Aviso do compilador (nível 1) C4959|não é possível definir o tipo não gerenciado 'type' em /CLR: safe como acessar seus membros resulta em código não verificado|  
|C4960 de aviso do compilador|'function' é muito grande para criação de perfil|  
|C4961 de aviso do compilador|Nenhum dado de perfil foi mesclado 'arquivo. PGD,' otimizações guiadas por perfil desabilitadas|  
|C4962 de aviso do compilador|'function': otimizações guiadas por perfil desabilitadas porque as otimizações dados de perfil para se tornar inconsistente|  
|C4963 de aviso do compilador|%s: nenhum dado de perfil foi encontrado; Opções do compilador diferentes foram usadas na compilação instrumentada|  
|[Compilador C4964 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4964.md)|Nenhuma opção de otimização foi especificada; informações de perfil não serão coletadas|  
|[Compilador C4965 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4965.md)|box implícito de inteiro 0; use nullptr ou conversão explícita|  
|C4966 de aviso do compilador|'%s' tem anotação __code_seg com o nome de segmento sem suporte, anotação ignorada|  
|C4970 de aviso do compilador|construtor delegate: objeto de destino ignorado porque '%$pS' é static|  
|Aviso do compilador (nível 1) C4971|Ordem do argumento: \<o objeto de destino >, \<função de destino > para o construtor delegado está obsoleto, use \<função de destino >, \<o objeto de destino = "" >|  
|Aviso do compilador (nível 1) C4972|Modificar diretamente ou tratar o resultado de uma operação de unbox como um lvalue não é verificável|  
|C4973 de aviso do compilador|'%$S': marcado como preterido|  
|C4974 de aviso do compilador|'%$S': marcado como preterido|  
|C4981 de aviso do compilador|Warbird: função '%$pD' marcada como __forceinline não embutida porque contém semântica de exceção|  
|Aviso do compilador (nível 3) C4985|nome de símbolo ': atributos não está presente na declaração anterior.|  
|[C4986 de aviso do compilador](../../error-messages/compiler-warnings/compiler-warning-c4986.md)|'%$pS': especificação de exceção não corresponde à declaração anterior|  
|Aviso do compilador (nível 4) C4987|extensão não padrão usada: 'throw (...)'|  
|Aviso do compilador (nível 4) C4988|'%$S': variável declarada fora do escopo de classe/função|  
|C4989 de aviso do compilador|'%s': tipo tem definições conflitantes.|  
|C4990 de aviso do compilador|Warbird: %s|  
|C4991 de aviso do compilador|Warbird: função '%$pD' marcada como __forceinline não embutida porque o nível de proteção do item embutido é superior ao do pai|  
|C4992 de aviso do compilador|Warbird: função '%$pD' marcada como __forceinline não embutida porque contém assembly embutido que não pode ser protegido|  
|[Compilador C4995 de aviso (nível 3)](../../error-messages/compiler-warnings/compiler-warning-level-3-c4995.md)|'function': nome foi marcado como #pragma preterido|  
|[Compilador (nível 3) aviso C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md)|'%$pS': %$*|  
|Aviso do compilador (nível 1) C4997|'class': coclass não implementa uma interface COM ou Pseudo-interface|  
|Aviso do compilador (nível 1) C4998|FALHA NA EXPECTATIVA: %s(%d)|  
|C4999 de aviso do compilador|AVISO DESCONHECIDO %$N Escolha o comando de Suporte Técnico no menu de Ajuda do Visual C++, %$N ou abra o arquivo de ajuda do Suporte Técnico para mais informações|
