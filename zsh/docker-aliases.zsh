alias d='docker'

alias dc='docker-compose'
alias dcd='docker-compose down'
alias dcu='docker-compose up'
alias dcub='docker-compose up --build'
alias dcud='docker-compose up -d'
alias dcubd='docker-compose up -d --build'
alias dce='docker-compose exec'
alias dcr='docker-compose run --rm'

alias dstop='docker stop $(docker ps -a -q)'
alias dtop='docker stats --format "table {{.Container}}\t{{.Name}}\t{{.CPUPerc}}  {{.MemPerc}}\t{{.NetIO}}\t{{.BlockIO}}"'
alias dnuke='docker system prune --volumes'
