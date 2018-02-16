---
title: "Os avisos do compilador são desativados por padrão | Microsoft Docs"
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- warnings, compiler
- cl.exe compiler, setting options
ms.assetid: 69809cfb-a38a-4035-b154-283a61938df8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4c447389de1accfe95674855645fe044e1d3df41
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="compiler-warnings-that-are-off-by-default"></a>Avisos de compilador desativados por padrão

O compilador inclui avisos que são desativados por padrão, pois a maioria dos usuários não deseja vê-los. No entanto, você pode habilitar esses avisos usando uma das opções a seguir.

**Aviso #pragma (padrão:** *warning_number* **)**  
O aviso especificado (*warning_number*) está habilitado no nível padrão. A documentação para o aviso contém o nível padrão do aviso.

**Aviso de #pragma (** *warning_level* **:** *warning_number* **)**  
O aviso especificado (*warning_number*) está habilitado no nível especificado (*warning_level*).

[/Wall](../build/reference/compiler-option-warning-level.md)  
**/ Parede** habilita todos os avisos que são desativados por padrão.

Os seguintes avisos são desativados por padrão.

|||
|-|-|
|[C4061](../error-messages/compiler-warnings/compiler-warning-level-4-c4061.md) (nível 4)|enumerador '*identificador*'em um switch de enum'*enumeração*' não é manipulado explicitamente por um rótulo case|
|[C4062](../error-messages/compiler-warnings/compiler-warning-level-4-c4062.md) (nível 4)|enumerador '*identificador*'em um switch de enum'*enumeração*' não é manipulado|
|C4191 (nível 3)|'*operador*': conversão não segura de '*type_of_expression*'para'*type_required*'|
|[C4242](../error-messages/compiler-warnings/compiler-warning-level-4-c4242.md) (nível 4)|'*identificador*': conversão de '*type1*'para'*type2*', possível perda de dados|
|[C4254](../error-messages/compiler-warnings/compiler-warning-level-4-c4254.md) (nível 4)|'*operador*': conversão de '*type1*'para'*type2*', possível perda de dados|
|[C4255](../error-messages/compiler-warnings/compiler-warning-level-4-c4255.md) (nível 4)|'*função*': nenhum protótipo de função fornecido: convertendo '()' para '(void)'|
|[C4263](../error-messages/compiler-warnings/compiler-warning-level-4-c4263.md) (nível 4)|'*função*': função membro não substitui nenhuma função de membro virtual de classe base|
|[C4264](../error-messages/compiler-warnings/compiler-warning-level-1-c4264.md) (nível 1)|'*virtual_function*': nenhuma substituição disponível para função membro virtual da Base de dados de '*classe*'; função é ocultada|
|[C4265](../error-messages/compiler-warnings/compiler-warning-level-3-c4265.md) (nível 3)|'*classe*': classe possui funções virtual, mas destruidor não virtual|
|[C4266](../error-messages/compiler-warnings/compiler-warning-level-4-c4266.md) (nível 4)|'*função*': nenhuma substituição disponível para função membro virtual da Base de dados de '*tipo*'; função é ocultada|
|[C4287](../error-messages/compiler-warnings/compiler-warning-level-3-c4287.md) (nível 3)|'*operador*': incompatibilidade de constante unsigned/negativa|
|[C4289](../error-messages/compiler-warnings/compiler-warning-level-4-c4289.md) (nível 4)|extensão não padrão usada: '*var*': variável de controle de loop declarada no loop for é usada fora do escopo de loop for|
|[C4296](../error-messages/compiler-warnings/compiler-warning-level-4-c4296.md) (nível 4)|'*operador*': expressão sempre é false|
|[C4339](../error-messages/compiler-warnings/compiler-warning-level-4-c4339.md) (nível 4)|'*tipo*': uso de tipo indefinido detectado em metadados do CLR - uso deste tipo pode levar a uma exceção de tempo de execução|
|[C4342](../error-messages/compiler-warnings/compiler-warning-level-1-c4342.md) (nível 1)|alteração de comportamento: '*função*' chamado, mas um operador membro foi chamado em versões anteriores|
|[C4350](../error-messages/compiler-warnings/compiler-warning-level-1-c4350.md) (nível 1)|alteração de comportamento: '*membro1*'chamado em vez de'*membro2*'|
|[C4355](../error-messages/compiler-warnings/compiler-warning-c4355.md)|'this' : usado na lista de inicializadores do membro base|
|[C4365](../error-messages/compiler-warnings/compiler-warning-level-4-c4365.md) (nível 4)|'*ação*': conversão de '*type_1*'para'*type_2*', incompatibilidade assinada/não assinada|
|C4370 (nível 3)|layout da classe foi alterado de uma versão anterior do compilador devido a empacotamento melhor|
|[C4371](../error-messages/compiler-warnings/c4371.md) (nível 3)|'*classname*': layout da classe pode ter sido alterado de uma versão anterior do compilador devido a melhor empacotamento do membro '*membro*'|
|C4388 (nível 4)|incompatibilidade de signed/unsigned|
|[C4412](../error-messages/compiler-warnings/compiler-warning-level-2-c4412.md) (nível 2)|'*função*': assinatura de função contém tipo '*tipo*'; Objetos C++ são seguros para passar entre código puro e código misto ou nativo|
|C4426 (nível 1)|os sinalizadores de otimização alterados após incluir o cabeçalho, pode ser devido a #pragma optimize()|
|[C4435](../error-messages/compiler-warnings/compiler-warning-level-4-c4435.md) (nível 4)|'*class1*': layout de objeto em /vd2 será alterado devido à base virtual '*class2*'|
|[C4437](../error-messages/compiler-warnings/compiler-warning-level-4-c4437.md) (nível 4)|dynamic_cast da base virtual '*class1*'para'*class2*' pode falhar em alguns contextos|
|C4444 (nível 3)|top level '__unaligned' não é implementado nesse contexto|
|C4464 (nível 4)|caminho de inclusão relativo contém '... '|
|C4472 (nível 1)|'*identificador*' é um enum nativo: adicionar um especificador de acesso (pública/privada) para declarar um enum gerenciado|
|[C4514](../error-messages/compiler-warnings/compiler-warning-level-4-c4514.md) (nível 4)|'*função*': função inline não referenciada foi removida|
|[C4536](../error-messages/compiler-warnings/compiler-warning-level-4-c4536.md) (nível 4)|nome do tipo: nome de tipo excede o limite de metadados de '*limite*' caracteres|
|[C4545](../error-messages/compiler-warnings/compiler-warning-level-1-c4545.md) (nível 1)|expressão antes da vírgula é avaliada para uma função que está ausente em uma lista de argumentos|
|[C4546](../error-messages/compiler-warnings/compiler-warning-level-1-c4546.md) (nível 1)|faltando lista de argumentos na chamada de função antes da vírgula|
|[C4547](../error-messages/compiler-warnings/compiler-warning-level-1-c4547.md) (nível 1)|'*operador*': operador antes da vírgula não tem nenhum efeito; esperado operador com efeito colateral|
|[C4548](../error-messages/compiler-warnings/compiler-warning-level-1-c4548.md) (nível 1)|expressão antes da vírgula não tem efeito; expressão esperada com efeito colateral|
|[C4549](../error-messages/compiler-warnings/compiler-warning-level-1-c4549.md) (nível 1)|'*operator1*': operador antes da vírgula não tem nenhum efeito; você pretendia usar '*operator2*'?|
|[C4555](../error-messages/compiler-warnings/compiler-warning-level-1-c4555.md) (nível 1)|expressão não tem efeito; expressão esperada com efeito colateral|
|[C4557](../error-messages/compiler-warnings/compiler-warning-level-3-c4557.md) (nível 3)|'__assume' contém o efeito '*efeito*'|
|[C4571](../error-messages/compiler-warnings/compiler-warning-level-4-c4571.md) (nível 4)|Informativo: semântica catch(...) alterada desde o Visual C++ 7.1; exceções estruturadas (SEH) não são mais capturadas|
|C4574 (nível 4)|'*identificador*'está definido como ' 0': você pretendia usar ' #if *identificador*'?|
|C4582 (nível 4)|'*tipo*': construtor não é chamado implicitamente|
|C4583 (nível 4)|'*tipo*': destrutor não está chamado implicitamente|
|C4587 (nível 1)|'*anonymous_structure*': alteração de comportamento: construtor é não mais implicitamente chamado|
|C4588 (nível 1)|'*anonymous_structure*': alteração de comportamento: destruidor é não mais implicitamente chamado|
|C4598 (níveis 1 e 3)|' #include "*cabeçalho*"': número de cabeçalho *número* no cabeçalho pré-compilado não coincide com a compilação atual da posição|
|C4599 (nível 3)|'*opção* *caminho*': o número de argumento de linha de comando *número* não coincide com cabeçalho pré-compilado|
|C4605 (nível 1)|' /D*macro*' especificado na linha de comando atual, mas não foi especificado quando o cabeçalho pré-compilado foi criado|
|[C4619](../error-messages/compiler-warnings/compiler-warning-level-3-c4619.md) (nível 3)|Aviso #pragma: há um número de aviso '*número*'|
|[C4623](../error-messages/compiler-warnings/compiler-warning-level-4-c4623.md) (nível 4)|'derived class': construtor padrão não pôde ser gerado porque o construtor padrão de uma classe base está inacessível|
|[C4625](../error-messages/compiler-warnings/compiler-warning-level-4-c4625.md) (nível 4)|'derived class': construtor de cópia não pôde ser gerado porque o construtor de cópia de uma classe base está inacessível|
|[C4626](../error-messages/compiler-warnings/compiler-warning-level-4-c4626.md) (nível 4)|'derived class': operador de atribuição não pôde ser gerado porque o operador de atribuição de uma classe base está inacessível|
|[C4628](../error-messages/compiler-warnings/compiler-warning-level-1-c4628.md) (nível 1)|dígrafos não suportados com -Ze. Sequência de caracteres '*dígrafo*'não é interpretada como token alternativo para'*char*'|
|[C4640](../error-messages/compiler-warnings/compiler-warning-level-3-c4640.md) (nível 3)|'*instância*': construção de objeto static local não é thread-safe|
|C4647 (nível 3)|alteração de comportamento: is_pod (*tipo*) tem um valor diferente em versões anteriores|
|C4654 (nível 4)|Incluir código colocado antes de cabeçalho pré-compilado linha será ignorada. Adicione código ao cabeçalho pré-compilado.|
|[C4668](../error-messages/compiler-warnings/compiler-warning-level-4-c4668.md) (nível 4)|'*símbolo*'não está definido como uma macro de pré-processador, substituindo por '0' para'*diretivas*'|
|[C4682](../error-messages/compiler-warnings/compiler-warning-level-4-c4682.md) (nível 4)|'*símbolo*': nenhum atributo de parâmetro direcional especificado, padronizando para [in]|
|[C4686](../error-messages/compiler-warnings/compiler-warning-level-3-c4686.md) (nível 3)|'*tipo definido pelo usuário*': possível alteração em comportamento, alteração no UDT retornar a convenção de chamada|
|[C4692](../error-messages/compiler-warnings/compiler-warning-level-1-c4692.md) (nível 1)|'*função*': assinatura de membro não private contém tipo nativo private de assembly '*native_type*'|
|[C4710](../error-messages/compiler-warnings/compiler-warning-level-4-c4710.md) (nível 4)|'*função*': função não embutida|
|[C4738](../error-messages/compiler-warnings/compiler-warning-level-3-c4738.md) (nível 3)|armazenando o resultado float de 32 bits na memória, possível perda de desempenho|
|[C4746](../error-messages/compiler-warnings/compiler-warning-c4746.md)|acesso volátil de '*expressão*' está sujeito a /volatile:\<iso &#124; ms > Configuração; considere o uso de funções intrínsecas iso_volatile_load/store|
|C4749 (nível 4)|condicionalmente com suporte: offsetof aplicado a tipo de layout não standard '*tipo*'|
|C4767 (nível 4)|nome da seção '*símbolo*' tem mais de 8 caracteres e será truncado pelo vinculador|
|C4768 (nível 3)|atributos de declspec antes de especificação de vinculação são ignorados|
|C4774 (nível 4)|'*cadeia de caracteres*': formato de cadeia de caracteres esperada no argumento *número* não é uma cadeia de caracteres literal|
|C4786 (nível 3)|'*símbolo*': nome do objeto foi truncado para '*número*' caracteres nas informações de depuração|
|[C4820](../error-messages/compiler-warnings/compiler-warning-level-4-c4820.md) (nível 4)|'*bytes*'bytes de preenchimento adicionados após a construção'*member_name*'|
|C4826 (nível 2)|Conversão de '*type1*'para'*type2*' possui sinal estendido. Isso pode causar comportamento inesperado em tempo de execução.|
|C4837 (nível 4)|trigraph detectado: '? *caracteres*'substituído por'*caracteres*'|
|C4841 (nível 4)|extensão não padrão usada: designador de membro composta usado em offsetof|
|C4842 (nível 4)|o resultado de 'offsetof' aplicado a um tipo usando várias heranças não é garantido para ser consistente entre as versões do compilador|
|[C4868](../error-messages/compiler-warnings/compiler-warning-c4868.md) (nível 4)|'_arquivo_(*line_number*)' compilador não pode impor a ordem de avaliação da esquerda para a direita na lista de inicialização entre chaves|
|[C4905](../error-messages/compiler-warnings/compiler-warning-level-1-c4905.md) (nível 1)|literal amplo de cadeia de caracteres convertido em 'LPSTR'|
|[C4906](../error-messages/compiler-warnings/compiler-warning-level-1-c4906.md) (nível 1)|literal de cadeia de caracteres convertido em 'LPWSTR'|
|[C4917](../error-messages/compiler-warnings/compiler-warning-level-1-c4917.md) (nível 1)|'*declarador*': um GUID só pode ser associado com um namespace, interface ou classe|
|[C4928](../error-messages/compiler-warnings/compiler-warning-level-1-c4928.md) (nível 1)|inicialização de cópia ilegal; mais de uma conversão definida pelo usuário foi implicitamente aplicada|
|[C4931](../error-messages/compiler-warnings/compiler-warning-level-4-c4931.md) (nível 4)|estamos supondo que a biblioteca de tipos foi criada para ponteiros de bit por número|
|[C4946](../error-messages/compiler-warnings/compiler-warning-level-1-c4946.md) (nível 1)|reinterpret_cast usado entre classes relacionadas: '*class1*'e'*class2*'|
|C4962|'*função*': otimizações guiadas por perfil desabilitadas porque otimizações fizeram dados de perfil se tornar inconsistente|
|[C4986](../error-messages/compiler-warnings/compiler-warning-c4986.md) (nível 4)|'*símbolo*': especificação de exceção não corresponde à declaração anterior|
|C4987 (nível 4)|extensão não padrão usada: 'throw (...)'|
|C4988 (nível 4)|'*símbolo*': variável declarada fora do escopo classe/função|
|C5022|'*tipo*': vários construtores de movimento especificados|
|C5023|'*tipo*': vários operadores de atribuição de movimento especificados|
|C5024 (nível 4)|'*tipo*': construtor de movimento foi implicitamente definido como excluído|
|C5025 (nível 4)|'*tipo*': mover o operador de atribuição foi implicitamente definido como excluído|
|C5026 (nível 1 e nível 4)|'*tipo*': construtor de movimento foi implicitamente definido como excluído|
|C5027 (nível 1 e nível 4)|'*tipo*': mover o operador de atribuição foi implicitamente definido como excluído|
|C5029 (nível 4)|extensão não padrão usada: atributos de alinhamento no C++ se aplicam a variáveis, membros de dados e somente os tipos de marcas|
|C5031 (nível 4)|Warning (POP) #pragma: provável incompatibilidade, estado de aviso enviado em outro arquivo mostrado|
|C5032 (nível 4)|detectado Warning (push) #pragma com nenhuma Warning (POP) #pragma correspondente|
|C5035|o uso de recurso '*recurso*' faz com que a função *função* a ser compilado como código do convidado|
|C5036 (nível 1)|conversão de ponteiro de função varargs ao compilar com /hybrid:x86arm64 '*type1*'para'*type2*'|

Esses avisos são desativados, a menos que o [/ permissivo-](../build/reference/permissive-standards-conformance.md) é definir a opção de compilador:

|||
|-|-|
|[C4471 (nível 4)](../error-messages/compiler-warnings/compiler-warning-level-4-c4471.md)|uma declaração de encaminhamento de uma enumeração sem escopo deve ter um tipo subjacente (int assumido)|
|[C4608 (nível 3)](../error-messages/compiler-warnings/compiler-warning-level-3-c4608.md)|'*union_member*'já foi inicializada por outro membro de união na lista de inicializador'*union_member*'|

Esses avisos foram desativado por padrão em versões do compilador antes do Visual Studio 2015:

|||
|-|-|
|[C4302](../error-messages/compiler-warnings/compiler-warning-level-2-c4302.md) (nível 2)|'*conversão*': truncamento de '*type1*'para'*type2*'|
|[C4311](../error-messages/compiler-warnings/compiler-warning-level-1-c4311.md) (nível 1)|'*variável*': truncamento de ponteiro de '*tipo*'para'*tipo*'|
|[C4312](../error-messages/compiler-warnings/compiler-warning-level-1-c4312.md) (nível 1)|'*operação*': conversão de '*type1*'para'*type2*' de tamanho maior|
|[C4319](../error-messages/compiler-warnings/compiler-warning-level-1-c4319.md) (nível 1)|'*operador*': zero estendendo '*type1*'para'*type2*' de tamanho maior|

Esses avisos foram desativado por padrão em versões do compilador antes do Visual Studio 2012:

|||
|-|-|
|[C4431](../error-messages/compiler-warnings/compiler-warning-level-4-c4431.md) (nível 4)|faltando especificador de tipo - int assumido. Observação: C não suporta mais default-int|

## <a name="see-also"></a>Consulte também

[warning](../preprocessor/warning.md)
